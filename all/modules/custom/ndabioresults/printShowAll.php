<?php
function printShowAll ($data) {
    $output = '';
    if (!isset($data['showAll']) || empty($data['showAll'])) {
        return $output;
    }
    $output = '<div class="show-all"><a href="?nba_request=' . $data['showAll'] . '">' .
        '<i class="icon-arrow-right"></i>'.
        t('Show all') . ' ' . $data['total'] . ' '. t('results') . '</a></div>';
    return $output;
}