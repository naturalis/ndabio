<?php
/**
 * Prints Show all... link
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function printShowAll ($data) {
    $output = '';
    if (!isset($data['showAll']) || empty($data['showAll'])) {
        return $output;
    }
    $output = '<div class="show-all"><a href="?nba_request=' . $data['showAll'] . '">' .
        '<i class="icon-arrow-right"></i>'.
        t('Show all') . ' ' . _formatNumber($data['total']) . ' '. t('results') . '</a></div>';
    return $output;
}