

function CurrencyControl($scope, $http)
{
	$scope.supported_currencies = [{ name :'GBP', symbol : '£'}, {name: 'EUR', symbol:'€'}, {name:'USD', symbol:'$'}];
	$scope.rate = 1;
	$scope.amount = 1;
	$scope.currency_from = $scope.supported_currencies[0];
	$scope.currency_to = $scope.supported_currencies[0];

	$scope.change_currencies = function()
	{
		$http({
				url:'/rates',
				params : {
					from : $scope.currency_from.name,
					to : $scope.currency_to.name
				}
		}).success(function(data, status, headers, config){
			if(typeof data == 'string')
			{
				data = JSON.parse(data);
			}

			$scope.rate = data.rate;
		});
	}

	$scope.weswap_total = function()
	{
		return ($scope.amount * $scope.rate * 0.99).toFixed(2);
	}

	$scope.highstreet_total = function()
	{
		return ($scope.amount * $scope.rate * 0.95).toFixed(2);
	}

	$scope.airport_total = function()
	{
		return ($scope.amount * $scope.rate * 0.89).toFixed(2);
	}
}
