<?php
require('./server/Cache.inc');
require('./server/utils.inc');
require('./server/CurrencyConverter.inc');
require ('./server/config.inc');

class WebAppRequest
{
	public function __construct($url, $function)
	{
		$this->url = $url;
		$this->cache = new Cache(MEMCACHED_SERVER, MEMCACHED_PORT);
		$this->function = $function;
	}

	public function run()
	{
		$function_name = $this->function;
		$this->$function_name($this->url, $this->cache);
	}

	function get_rate($url, $cache)
	{
		$converter = new CurrencyConverter($cache);
		$rate = $converter->get_rate($_GET['from'], $_GET['to']);
		print json_encode($rate);
	}

}

class WebApp
{
	private static $functions = array(
		'/rates' => 'get_rate'
	);

	function route($url)
	{
		$url = substr($url, 0, strpos($url,'?'));
		$function_name = self::$functions[$url];

		$req = new WebAppRequest($url, $function_name);
		$req->run();
	}

}
