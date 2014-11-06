<?php
function printShowAll ($data) {
    $output = '';
    if (!isset($data['showAll']) || empty($data['showAll'])) {
        return $output;
    }
    $output = '<div class="show-all"><a href="' . $data['showAll'] . '">' .
        t('Show all') . ' ' . $data['total'] . '</a></div>';
    return $output;
}