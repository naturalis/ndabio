<?php
/**
 * @file
 * bioportal_serrvice_menu_pages.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function bioportal_serrvice_menu_pages_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'title' => 'Disclaimer',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'und',
  'created' => 1413896301,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '1dfa43fc-f62c-4d40-a016-4e4f40952954',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Every effort has been taken to ensure the accuracy of the information on www.naturalis.nl.</p>

<p>However, Naturalis Biodiversity Center excludes all and any liability for damage resulting from the use, in whatever manner, of information supplied on this site.</p>

<h2>Intellectual Property Rights</h2>

<p>Every effort has been taken to protect the interests of third parties when using data, texts and pictures. If, however, you believe that this site contains material that is subject to intellectual property rights without agreements having been made with the rightful owner, please contact the web editors.</p>

<h2>Photography</h2>

<p>Photographs are regularly taken during activities in and around Naturalis Biodiversity Center, in particular in the Naturalis museum. Some of these pictures may be used for publicity purposes and/or posted on Naturalis Biodiversity Center sites. In view of the number of pictures involved and the great many faces visible in these photographs it is impossible to ask everyone for permission to publish. However, Naturalis Biodiversity Center carefully considers the interests of the persons portrayed. If a visitor nevertheless objects to the use of a particular photograph, that photograph will be removed on request.</p>
',
        'summary' => '',
        'format' => 'rich_text',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-21 14:58:21 +0200',
  'user_uuid' => '34d5f7f8-a951-4eb0-8639-297470a23f85',
);
  $nodes[] = array(
  'title' => 'Colophon',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'und',
  'created' => 1413895260,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '794d5b17-da10-492e-839d-bbfce2ad70b4',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The information on this website is copyrighted by Naturalis Biodiversity Center.</p>

<h2>Editing</h2>

<p>Naturalis Biodiversity Center</p>

<h2>Contact</h2>

<p>For your questions and remarks, please contact our editorial staff at: redactie@naturalis.nl﻿</p>

<h2>Design and technique</h2>

<ul>
	<li>Fabrique [merken, design &amp; interactie]</li>
	<li>Naturalis Biodeversity Center [design, interactie, technique)</li>
</ul>
',
        'summary' => '',
        'format' => 'rich_text',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-21 14:41:00 +0200',
  'user_uuid' => '34d5f7f8-a951-4eb0-8639-297470a23f85',
);
  return $nodes;
}
