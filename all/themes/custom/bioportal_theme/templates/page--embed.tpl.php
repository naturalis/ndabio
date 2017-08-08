<?php

if (arg(0) == 'node' && is_numeric(arg(1))) $nid = arg(1);

$node = node_load($nid);

if ($node->status == 1) {
  echo ("<div class='embed-title'>" . $node->title . "</div>\n");
  echo ("<div class='embed-body'>" . $node->body['und'][0]['value'] . "</div>\n");
}

?>

