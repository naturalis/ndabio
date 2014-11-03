<?php

function printTableRow ($field, $value) {
	return "<tr><td>" . ($field != '' ? t(translateNdaField($field)) : '') . "</td><td>" .
		($value != '' ? $value : '') . "</td></tr>";
}


?>