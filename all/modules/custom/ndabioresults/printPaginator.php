<?php
/**
 * Prints paginator
 *
 * Data is already formatted in parsed array. This function merely
 * places the output in the proper div.
 *
 * @param array $row Parsed json data
 * @return string Formatted output
 */
function printPaginator ($data) {
    return _wrap($data['paginator'], "div", "paginator-wrapper small-12 columns");
}


