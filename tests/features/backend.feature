Scenario: The customer requests a quote for currency
	#using a proxy server to imitate the Currency API so we can control it

	Given the Currency API is working
		When the customer asks for a rate between USD and GBP
		Then our backend should return an object containing from : USD
			And containing to : GBP
			And a rate number (which we define in our proxy)

	Given the Currency API is working and we've just requested the same rate again
		When the customer asks for a rate between USD and GBP
		Then our backend should return an object containing from : USD
			And containing to : GBP
			And a rate number (which we define in our proxy)
			And the cache should return the value and not our proxy

	Given the Currency API is not working
		When the customer asks for a rate between USD and GBP
		Then our backend should return an object containing from : USD
			And containing to : GBP
			And a rate number (which we define in our proxy)
			And the cache should return the value and not our proxy
