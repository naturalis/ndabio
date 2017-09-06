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
function ndabioresults_block_view ($delta = '') {
	global $base_root, $base_path, $language;
	
	$icon = "<i class='icon-arrow-left'></i>";
	
	$block = array();
	
	$_link_enabled = array('attributes' => array('class' => 'filter-enabled'));
	$_link_disabled = array('attributes' => array('class' => 'filter-disabled'));
	$_link_active = array('attributes' => array('class' => 'filter-active'));
	
	switch ($delta) {
		
		case 'ndabioresults_back' :
			$block['content'] = '<div id="navigation-block">' . _getBackLinkFormatted() . '</div>';
			break;
		
		case 'ndabioresults_thematicsearch' :
			// Get NBA search term from URL
			$mytheme = isset($_GET['theme']) ? check_plain($_GET['theme']) : '';
			$block['content'] = "";
			if (!empty($mytheme)) {
				// Check if content with identical label is available
				// Get node of type 'Naturalis thematic search'
				$sql = "SELECT entity_id 
						FROM field_data_field_nba_search_term st, node n 
						WHERE st.field_nba_search_term_value = '" . $mytheme . "' AND st.entity_id = n.nid AND n.language = '" .
					 $language->language . "' LIMIT 1";
				$myid = db_query($sql)->fetchAssoc();
				
				if (empty($myid)) {
					$sql = "SELECT entity_id 
							FROM field_data_field_nba_search_term 
							WHERE field_nba_search_term_value = '" . $mytheme . "' AND language = 'und' LIMIT 1";
					$myid = db_query($sql)->fetchAssoc();
				}
				
				// SELECT nid FROM xxx WHERE label = $_POST['searchkey']
				$mynode = node_load($myid['entity_id']);
				if (!empty($mynode)) {
					// Create block content
					$block['subject'] = $mynode->title;
					
					// Set title for correct display of breadcrumb
					drupal_set_title($mynode->title);
					$mycontent = isset($mynode->body[$mynode->language][0]['value']) ?
						$mynode->body[$mynode->language][0]['value'] : 
						isset($mynode->body['und'][0]['value']) ? $mynode->body['und'][0]['value'] : '';
					$block['content'] = $mycontent . " ";
				}
			}
			
			break;
		
		case 'ndabioresults_thematicsearchmore' :
			// Get NBA search term from URL
			$mytheme = isset($_GET['theme']) ? check_plain($_GET['theme']) : '';
			$block['content'] = "";
			if (!empty($mytheme)) {
				// $block['content'] = drupal_render(drupal_get_form('ndabio_omnisearch_form'));
			}
			break;
	}
	return $block;
}

function _list_items ($arr_items){

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

function _item ($arr_item){
  return array(
    'data' => $arr_item[0],
    'class' => isset($arr_item[1]) ? $arr_item[1] : null,
    'value' => isset($arr_item[2]) ? $arr_item[2] : null
  );
}
