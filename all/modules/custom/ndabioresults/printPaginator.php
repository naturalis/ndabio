<?php
function printPaginator ($data) {
    
    return _wrap($data['paginator'], "div", "paginator-wrapper small-12 columns");
}


