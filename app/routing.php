<?php
    if (preg_match('/\/(bower_components|css|js|)\//', $_SERVER["REQUEST_URI"]) || $_SERVER["REQUEST_URI"] == '/') {
        return false;
    }
    else
	{

        include ('./server/main.php');

        $app = new WebApp();
        echo $app->route(array_key_exists('REQUEST_URI', $_SERVER) ? $_SERVER['REQUEST_URI'] : $_SERVER['HTTP_X_ORIGINAL_URL']);

    }
