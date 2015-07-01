<?php
function printMultimediaPreviousNext () {
    // Return "link-less" navigation if request is empty or history is not yet set
    if (!isset($_GET['nba_request']) ||
        !isset($_SESSION['ndaNavigation']['media']['currentSet'])) {
        return '<span class="icon button-icon icon-chevron-up icon-button-disabled"></span>
            <span class="icon button-icon icon-chevron-down icon-button-disabled"></span>
            <span class="icon button-icon icon-cross icon-button-disabled"></span>';
    }

    $set = $_SESSION['ndaNavigation']['media']['currentSet'];
    $key = array_search(urldecode($_GET['nba_request']),
        $_SESSION['ndaNavigation']['media']['currentSet']);
    $previousUrl = isset($set[$key - 1]) ? urldecode($set[$key - 1]) : false;
    $nextUrl = isset($set[$key + 1]) ? urldecode($set[$key + 1]) : false;

    $output = '<p class="button-bar">';

    $output .= '<span class="button-text">' . sprintf(
        t('%d of %d'),
        $_SESSION['ndaNavigation']['media']['offset'] + $key + 1,
        $_SESSION['ndaNavigation']['media']['total']
    ) . '</span>';

    if (!empty($previousUrl)) {
        $output .= '<a href="' . printDrupalLink($previousUrl) . '">';
    }
    $output .= '<span class="icon button-icon icon-chevron-up';
    if (empty($previousUrl)) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if (!empty($previousUrl)) {
        $output .= '</a>';
    }

    if (!empty($nextUrl)) {
        $output .= '<a href="' . printDrupalLink($nextUrl) . '">';
    }
    $output .= '<span class="icon button-icon icon-chevron-down';
    if (empty($nextUrl)) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if (!empty($nextUrl)) {
        $output .= '</a>';
    }

    $output .= '<a href="?back"><span class="icon button-icon icon-cross"></span></a>';


    $output .= '</p>';

    return $output;
}
?>