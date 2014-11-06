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
    'status' => TRUE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function ndabioresults_block_view($delta = '') {
  global $base_root, $base_path;
  $block = array();

  $_link_enabled =  array('attributes' => array('class' => 'filter-enabled'));
  $_link_disabled =  array('attributes' => array('class' => 'filter-disabled'));
  $_link_active =  array('attributes' => array('class' => 'filter-active'));

  switch ($delta) {
    case 'ndabioresults_collected_date':
      $block['subject'] = t('Collection date');

      $block['content'] =
        _list_items( array(
          _item(array('All periods','filter-selected')),
          _item(array('After 2010' ,'filter-enabled')),
          _item(array('Before 2010','filter-enabled')),
          _item(array('custom'     ,'filter-enabled','')),
        ));

      break;

    case 'ndabioresults_source':
      $block['subject'] = t('Sources');

      $block['content'] =
        _list_items( array(
          _item(array('Naturalis',          'filter-selected')),
          _item(array('the Netherlands',    'filter-disabled')),
          _item(array('Worldwide & the Web','filter-disabled')),
        ));

      break;

    case 'ndabioresults_category':
      $block['subject'] = t('Categories');

      $block['content'] =
        _list_items( array(
          _item(array('Multimedia'  ,'filter-selected')),
          _item(array('Taxons'      ,'filter-selected')),
          _item(array('Specimen'    ,'filter-selected')),
          _item(array('Observations','filter-disabled')),
        ));

      break;

  case 'ndabioresults_back':
      $block['subject'] = t('Back to search');

      $starturl = $base_root . $base_path;
      if (isset($_SESSION['ndaSearch']['geoShape'])) $starturl .= "geographic-search/";

      $block['content'] = "<a href='" . $starturl . "?searchagain=1'>" . t('Back to search') . "</a>";

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
    'class' => $arr_item[1],
    'value' => isset($arr_item[2]) ? $arr_item[2] : null
  );
}
