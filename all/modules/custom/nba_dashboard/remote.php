<?php
	if (!isset($_GET['url'])) return;
	echo file_get_contents($_GET['url']);
	