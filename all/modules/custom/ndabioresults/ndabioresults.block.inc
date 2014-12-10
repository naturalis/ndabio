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
    'pages' => "nba/result\nnba/result*",
    'region' => "content",
    'weight' => -10,
    'status' => TRUE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function ndabioresults_block_view($delta = '') {
  global $base_root, $base_path;
  $icon = "<i class='icon-arrow-left'></i>";

  $block = array();

  $_link_enabled =  array('attributes' => array('class' => 'filter-enabled'));
  $_link_disabled =  array('attributes' => array('class' => 'filter-disabled'));
  $_link_active =  array('attributes' => array('class' => 'filter-active'));

  $SHOWS_RESULTS = (
    $_SESSION['ndaPageDetail'] == 'result from simple form' ||
    $_SESSION['ndaPageDetail'] == 'results taxa' ||
    $_SESSION['ndaPageDetail'] == 'results multimedia' ||
    $_SESSION['ndaPageDetail'] == 'results specimens' ||
    $_SESSION['ndaPageDetail'] == 'result from advanced form'
  ) ;

  switch ($delta) {

    case 'ndabioresults_collected_date':
      if ( $SHOWS_RESULTS ){

        // $block['subject'] = t('Collection date');

        // $block['content'] =
        //   _list_items( array(
        //     _item(array('All periods','filter-selected')),
        //     _item(array('After 2010' ,'filter-enabled')),
        //     _item(array('Before 2010','filter-enabled')),
        //     _item(array('custom'     ,'filter-enabled','')),
        //   ));
      }

      break;

    case 'ndabioresults_source':
      // $block['subject'] = t('Sources');

      // $block['content'] =
      //   _list_items( array(
      //     _item(array('Naturalis',          'filter-selected')),
      //     _item(array('the Netherlands',    'filter-disabled')),
      //     _item(array('Worldwide & the Web','filter-disabled')),
      //   ));

      break;

    case 'ndabioresults_category':
      if ( $SHOWS_RESULTS  ){

       $block['subject'] = t('Categories');

        $multimediaUrl = isset($_SESSION['ndaFilters']['multimedia']) && !empty($_SESSION['ndaFilters']['multimedia']) ?
            '<a href="' . printDrupalLink($_SESSION['ndaFilters']['multimedia']) . '">Multimedia</a>' : null;
        $taxonUrl = isset($_SESSION['ndaFilters']['taxon']) && !empty($_SESSION['ndaFilters']['taxon']) ?
            '<a href="' . printDrupalLink($_SESSION['ndaFilters']['taxon']) . '">Taxa</a>' : null;
        $specimenNameUrl = isset($_SESSION['ndaFilters']['specimenName']) && !empty($_SESSION['ndaFilters']['specimenName']) ?
            '<a href="' . printDrupalLink($_SESSION['ndaFilters']['specimenName']) . '">' . t('Taxa with specimens') . '</a>' : null;
        $specimenUrl = isset($_SESSION['ndaFilters']['specimen']) && !empty($_SESSION['ndaFilters']['specimen']) ?
            '<a href="' . printDrupalLink($_SESSION['ndaFilters']['specimen']) . '">' . t('Specimens') . '</a>' : null;

        $block['content'] =
          _list_items( array(
            _item(array(
                !empty($multimediaUrl) ? $multimediaUrl : 'Multimedia',
                !empty($multimediaUrl) ? 'filter-selected' : 'filter-disabled'
            )),
            _item(array(
                !empty($taxonUrl) ? $taxonUrl : 'Taxa',
                !empty($taxonUrl) ? 'filter-selected' : 'filter-disabled'
            )),
            _item(array(
                !is_null($specimenNameUrl) ? $specimenNameUrl : t('Taxa with specimens'),
                !is_null($specimenNameUrl) ? 'filter-selected' : 'filter-disabled'
            )),
            _item(array(
                !empty($specimenUrl) ? $specimenUrl : t('Specimens'),
                !empty($specimenUrl) ? 'filter-selected' : 'filter-disabled'
            )),
            _item(array('Observations','filter-disabled')),
          ));
      }

      break;

    case 'ndabioresults_back':
      //$block['subject'] = '<none>';

      $starturl = $base_root . $base_path;
      if (isset($_SESSION['ndaSearch']['geoShape'])) $starturl .= "geographic-search/";

    if ( $_SESSION['ndaRequestType'] == 'form'){
        if ($_SESSION['ndaSearch']['theme'] && !empty($_SESSION['ndaSearch']['theme'])) {
            $block['content'] = "<a href='$starturl'>$icon" . t('Home') . "</a>";
        } else {
           $block['content'] = "<a href='" . $starturl . "?searchagain=1'>$icon" . t('Modify search') . "</a>";
        }
      } else {
          $block['content'] = "<a href='?back'>$icon" . t('Back to search results') . "</a>";
      }


      break;

    case 'ndabioresults_navigation':
      //$block['subject'] = '<none>';

      if ( !$SHOWS_RESULTS ){
      $block['content'] =
        "<div id='result-nav'>"
        // ._list_items( array(
        //   _item(array('7 van 35'    )),
        //   _item(array("<i class='icon-triangle-up'></i>"     )),
        //   _item(array("<i class='icon-triangle-down'></i>"     )),
        //   _item(array("<i class='icon-cross'></i>"     ))
        // ))
        ."</div>";
      }


      break;


    case 'ndabioresults_thematicsearch':
      //Get NBA search term from URL
      $mytheme = check_plain($_GET['theme']);
      if(!empty($mytheme)) {
        //Check if content with identical label is available
        //Get node of type 'Naturalis thematic search'
        $sql = "SELECT entity_id FROM field_data_field_nba_search_term WHERE field_nba_search_term_value = '" . $mytheme . "' LIMIT 1";
        $myid = db_query($sql)->fetchAssoc();

        //SELECT nid FROM xxx WHERE label = $_POST['searchkey']
        $mynode = node_load($myid['entity_id']);

        if (!empty($mynode)) {
          //Create block content
          $block['subject'] = $mynode->title;
          $block['content'] = $mynode->body['und'][0]['value'] . " ";
        }
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
