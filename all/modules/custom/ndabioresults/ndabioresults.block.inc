<?php

/**
 * Implements hook_block_info().
 */
function ndabioresults_block_info() {
  $blocks['ndabioresults_back'] = array(
    'info' => t('NBA: Search result back button'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => "nba/result\nnba/result*",
    'region' => "sidebar_first",
    'status' => TRUE,
  );

  $blocks['ndabioresults_navigation'] = array(
    'info' => t('NBA: Search result navigation'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => "nba/result\nnba/result*\nexplore*",
    'region' => "sidebar_second",
    'status' => TRUE,
  );

  $blocks['ndabioresults_collected_date'] = array(
    'info' => t('NBA: Search result collected'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => "nba/result\nnba/result*",
    'region' => "sidebar_first",
    'status' => TRUE,
  );

  $blocks['ndabioresults_source'] = array(
    'info' => t('NBA: Search result source'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => "nba/result",
    'region' => "sidebar_first",
    'status' => TRUE,
  );

  $blocks['ndabioresults_category'] = array(
    'info' => t('NBA: Search result category'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => "nba/result\nnba/result*",
    'region' => "sidebar_first",
    'status' => FALSE,
  );
  $blocks['ndabioresults_thematicsearch'] = array(
    'info' => t('NBA: Thematic search title block'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'cache' => DRUPAL_NO_CACHE,
    'pages' => "nba/result\nnba/result*",
    'region' => "content",
    'weight' => -10,
    'status' => TRUE,
  );
  $blocks['ndabioresults_thematicsearchmore'] = array(
    'info' => t('NBA: Thematic search more block'),
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'cache' => DRUPAL_NO_CACHE,
    'pages' => "nba/result\nnba/result*",
    'region' => "content",
    'weight' => -9,
    'status' => TRUE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function ndabioresults_block_view($delta = '') {
  global $base_root, $base_path, $language;
  
  $icon = "<i class='icon-arrow-left'></i>";

  $block = array();

  $_link_enabled =  array('attributes' => array('class' => 'filter-enabled'));
  $_link_disabled =  array('attributes' => array('class' => 'filter-disabled'));
  $_link_active =  array('attributes' => array('class' => 'filter-active'));


  switch ($delta) {

    case 'ndabioresults_back':
     $block['content'] = '<div id="navigation-block">' . _getBackLinkFormatted() . '</div>';
    
    /*
    
    $pathComponents = explode('/', current_path());
    
    // General result page; go to back to search page
    if (count($pathComponents) == 1 && $pathComponents[0] == 'result') {
    	$output .= "<a href='" . _setStartUrl() . "?searchagain=1'>$icon" . t('Modify search') . "</a>";
    	//drupal_set_title(t("Search results"));
    	
    // List page for category
    } else if (count($pathComponents) > 1 && $pathComponents[0] == 'result') {
    	// From specimen by taxon
     	if (count($pathComponents) == 5) {
     		// From search result
     		if (strpos($pathComponents[4], 'EQUALS') === false) {
		     	$output .= '<a href="' . _setStartUrl() . 'result/specimen/' . $pathComponents[4] .
		    		'">' . $icon . t('Back to search results') . '</a>';
     		// From taxon detail page
     		} else if (_getReferredSearch($pathComponents[4])) {
		     	$output .= '<a href="' . _setStartUrl() . 'taxon/' . 
				    ucfirst(str_replace(' ', '_', $pathComponents[3])) . '/' .
					_getReferredSearch($pathComponents[4]) . '">' . $icon . t('Back to taxon') . '</a>';
     		}
    	} else if (isset($_SESSION['nbaSearch']) && !empty($_SESSION['nbaSearch'])) {
	     	$output .= '<a href="' . _setStartUrl() . 'result?' . 
	     		http_build_query($_SESSION['nbaSearch']) .
	    		'">' . $icon . t('Back to general results') . '</a>';
    	}
    	//drupal_set_title(t("Search results"));
    	
    // Detail page
    } else if (in_array($pathComponents[0], ['multimedia', 'specimen', 'taxon']) && 
    	count($pathComponents) >= 3) {
    	// From taxon/specimen detail multimedia overview
    	if ($pathComponents[0] == 'multimedia' && _getReferredSearch($pathComponents[2])) {	
    		$output .= _getBackLinkFormatted();
     	} else {
	    	// From taxon detail specimen overview
	    	if (_getReferredSearch($pathComponents[3])) {
	    		$label = 'Back to specimens';
	    	} else {
	    		$label = 'Back to search results';
	    	}
	     	$function = '_set' . ucfirst($pathComponents[0]) . 'DetailPageBackLink';
			$href = $function($pathComponents);  
			$output .= '<a href="' . $href . '">' . $icon . t($label) . '</a>';
	   }
    
    // Fallback
  	} else {
        $output .= '&nbsp;';
    }
    
    */
/*
    if ($_SESSION['nbaRequestType'] == 'form') {
        if (isset($_SESSION['nbaSearch']['theme']) && !empty($_SESSION['nbaSearch']['theme'])) {
            $output .= "<a href='" . setStartUrl() . "'>$icon" . t('Home') . "</a>";
        } else {
           $output .= "<a href='" . setStartUrl() . "?searchagain=1'>$icon" . t('Modify search') . "</a>";
        }
    } else if (isset($_SESSION['nbaSearch']) && !empty($_SESSION['nbaSearch'])) {
        $output .= "<a href='?back'>$icon" . t('Back to search results') . "</a>";
        drupal_set_title(t("Search results"));
    } else {
        $output .= '&nbsp;';
    }

      $block['content'] = $output;
*/      
    break;


    // Used now to create some space on detail pages
    case 'ndabioresults_navigation':
    	/*
      if ( !$SHOWS_RESULTS ){
        $block['content'] =  '&nbsp;';
      }


      break;
      */


    case 'ndabioresults_thematicsearch':
      //Get NBA search term from URL
      $mytheme = isset($_GET['theme']) ? check_plain($_GET['theme']) : '';
      $block['content'] = "";
      if(!empty($mytheme)) {
        //Check if content with identical label is available
        //Get node of type 'Naturalis thematic search'
        $sql = "SELECT entity_id FROM field_data_field_nba_search_term st, node n WHERE st.field_nba_search_term_value = '" . $mytheme . "' AND st.entity_id = n.nid AND n.language = '" . $language->language . "' LIMIT 1";
        $myid = db_query($sql)->fetchAssoc();

        if(empty($myid)) {
          $sql = "SELECT entity_id FROM field_data_field_nba_search_term WHERE field_nba_search_term_value = '" . $mytheme . "' AND language = 'und' LIMIT 1";
          $myid = db_query($sql)->fetchAssoc();
        }

        //SELECT nid FROM xxx WHERE label = $_POST['searchkey']
        $mynode = node_load($myid['entity_id']);
        if (!empty($mynode)) {
          //Create block content
          $block['subject'] = $mynode->title;

	  //Set title for correct display of breadcrumb
	  drupal_set_title($mynode->title);
	  $mycontent = $mynode->body[$mynode->language][0]['value'];

          if (empty($mycontent)) $mycontent = $mynode->body['und'][0]['value'];
          $block['content'] = $mycontent . " ";
        }
      }

      break;
    case 'ndabioresults_thematicsearchmore':
      //Get NBA search term from URL
      $mytheme = isset($_GET['theme']) ? check_plain($_GET['theme']) : '';
      $block['content'] = "";
      if(!empty($mytheme)) {
        //$block['content'] = drupal_render(drupal_get_form('ndabio_omnisearch_form'));
      }
      break;
  }
  return $block;
}

function _list_items($arr_items){

  $str_return = "<ul class='no-bullets'>";

  foreach($arr_items as $item){
    $str_return .=
       "<li>"
      ."  <a class='".$item['class']."'>"
      .     $item['data']
      ."  </a>"
      ."</li>";
  }

  $str_return .= "</ul>";

  return $str_return;
}

function _item($arr_item){
  return array(
    'data' => $arr_item[0],
    'class' => isset($arr_item[1]) ? $arr_item[1] : null,
    'value' => isset($arr_item[2]) ? $arr_item[2] : null
  );
}
