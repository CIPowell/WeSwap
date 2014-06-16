<?php
/**
 *  Kept as a seperate class so that if we decided to use a Cache other then memcached we can keep the interface the same
 */
class Cache
{
	public $server;
	private $connection;
	private $memcached_port;

	public function __construct($memcached_server, $memcached_port = 11211)
	{
	//	$this->server = $memcached_server;

	//	$this->connection = new Memcached();
	//	$$this->connection->connect($memcached_server, $memcached_port);
	}

	public function get($key)
	{
	//	return $this->connection->get($key);
		return false;
	}

	public function set($key, $data, $expiration)
	{
	//	return $this->connection->set($key, $data, $expiration);
		return true;
	}

	public function touch($key, $expiration)
	{
	//	return $this->connection->set($key, $expiration);
		return true;
	}

}
