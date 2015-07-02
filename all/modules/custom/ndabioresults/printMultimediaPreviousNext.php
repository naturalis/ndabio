<?php
function printMultimediaPreviousNext () {
//p($_SESSION['ndaNavigation']['media']);

    // Return "link-less" navigation if request is empty or history is not yet set
    if (!isset($_GET['nba_request']) ||
        !isset($_SESSION['ndaNavigation']['media']['currentSet'])) {
        return '<span class="icon button-icon icon-chevron-up icon-button-disabled"></span>
            <span class="icon button-icon icon-chevron-down icon-button-disabled"></span>
            <span class="icon button-icon icon-cross icon-button-disabled"></span>';
    }

    $set = $_SESSION['ndaNavigation']['media']['currentSet'];
    $offset = $_SESSION['ndaNavigation']['media']['offset'];
    $key = array_search(urldecode($_GET['nba_request']),
        $_SESSION['ndaNavigation']['media']['currentSet']);

    //$previousUrl = isset($set[$key - 1]) ? urldecode($set[$key - 1]) : false;
    //$nextUrl = isset($set[$key + 1]) ? urldecode($set[$key + 1]) : false;

    $previousUrl = false;
    // Scroll through set
    if (isset($set[$key - 1])) {
        $previousUrl = urldecode($set[$key - 1]);
    // First item of set reached; check if there's a previousSet.
    // If so, reset $_SESSION['ndaNavigation']['media']
    } else if (!empty($_SESSION['ndaNavigation']['media']['previousSet'])) {
        updatePreviousNext($_SESSION['ndaNavigation']['media']['previousSet']);
        $previousUrl = end($_SESSION['ndaNavigation']['media']['currentSet']);
        //$key = array_search($previousUrl, $_SESSION['ndaNavigation']['media']['currentSet']);
    }

    $nextUrl = false;
    // Scroll through set
    if (isset($set[$key + 1])) {
        $nextUrl = urldecode($set[$key + 1]);
    // Last item of set reached; check if there's a nextSet.
    } else if (!empty($_SESSION['ndaNavigation']['media']['nextSet'])) {
//p($_SESSION['ndaNavigation']['media']);
        updatePreviousNext($_SESSION['ndaNavigation']['media']['nextSet']);
//p($_SESSION['ndaNavigation']['media']);
        $nextUrl = reset($_SESSION['ndaNavigation']['media']['currentSet']);
        //$key = array_search($nextUrl, $_SESSION['ndaNavigation']['media']['currentSet']);
    }

    $output = '<p class="button-bar">';

    $output .= '<span class="button-text">' . sprintf(
        t('%d of %d'),
        $offset + $key + 1,
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