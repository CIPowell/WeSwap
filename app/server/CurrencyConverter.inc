<?php
Class CurrencyConverter
{
	static $API_URL = 'http://rate-exchange.appspot.com/currency';

	function __construct($cache)
	{
		$this->cache = $cache;
	}

	function get_rate($currency_from, $currency_to)
	{
		$api_url = sprintf('%s?from=%s&to=%s', self::$API_URL, $currency_from, $currency_to);

		//check memcached
		$rate_json = $this->cache->get($cached_key);

		if(!$rate_json)
		{

			//if the record isn't in memcached or has expired try and get it
			$rate_json = Utils::get_url($api_url);

			if($rate_json === false)
			{
				//if the request fails reacache for 5 mins and use the cached value
				$this->cache->touch($api_url, 300);
				$rate_json = $this->cache->get($api_url);
			}
		}

		return json_decode($rate_json);
	}



}
