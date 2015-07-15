<?php
function printMultimediaPreviousNext () {
    // Return no navigation if request is empty or history is not yet set
    // (eg when user comes from bookmark)

    if (!isset($_GET['nba_request']) || !getSearchId($_GET['nba_request'])) {
        return false;
    }

    $searchId = getSearchId($_GET['nba_request']);
    $request = stripNbaBaseUrl($_GET['nba_request']);

    $set = $_SESSION['ndaNavigation'][$searchId]['currentSet'];
    $offset = $_SESSION['ndaNavigation'][$searchId]['offset'];
    $key = array_search(stripNbaBaseUrl($_GET['nba_request']),
        $_SESSION['ndaNavigation'][$searchId]['currentSet']);

    $previousUrl = false;
    // Scroll through set
    if (isset($set[$key - 1])) {
        $previousUrl = urldecode($set[$key - 1]);
    // First item of set reached; check if there's a previousSet.
    // If so, reset $_SESSION['ndaNavigation']['media']
    } else if (!empty($_SESSION['ndaNavigation'][$searchId]['previousSet'])) {
        $previousSearchId = updatePreviousNext($_SESSION['ndaNavigation'][$searchId]['previousSet']);
        $previousUrl = end($_SESSION['ndaNavigation'][$previousSearchId]['currentSet']);
    }

    $nextUrl = false;
    // Scroll through set
    if (isset($set[$key + 1])) {
        $nextUrl = urldecode($set[$key + 1]);
    // Last item of set reached; check if there's a nextSet.
    } else if (!empty($_SESSION['ndaNavigation'][$searchId]['nextSet'])) {
        $nextSearchId = updatePreviousNext($_SESSION['ndaNavigation'][$searchId]['nextSet']);
        $nextUrl = reset($_SESSION['ndaNavigation'][$nextSearchId]['currentSet']);
    }

    $output = '<div class="fornext-bar"><ul>';

    // Count
    $output .= '<li>' . sprintf(
        t('%d of %d'),
        $offset + $key + 1,
        $_SESSION['ndaNavigation'][$searchId]['total']
    ) . '</li>';

    // Previous
    $output .= "<li>";

    if ($previousUrl) {
        $output .= '<a href="' . printDrupalLink($previousUrl) . '">';
    }
    $output .= '<span class="icon button-icon icon-chevron-up';
    if (!$previousUrl) {
        $output .= ' icon-button-disabled';
    }
    $output .= '"></span>';
    if ($previousUrl) {
        $output .= '</a>';
    }
    $output .="</li>";

    // Next
    $output .= "<li>";
    if ($nextUrl) {
        $output .= '<a href="' . printDrupalLink($nextUrl) . '">';
    }

    $output .= '<span class="icon button-icon icon-chevron-down';

    if (!$nextUrl) {
        $output .= ' icon-button-disabled';
    }

    $output .= '"></span>';


    if ($nextUrl) {
        $output .= '</a>';
    }

    $output .= '</li>';

    // Back
    $output .= '<li><a href="?back"><span class="icon button-icon icon-cross"></span></a></li>';
    $output .= '</ul></div>';

    return $output;
}
?>
