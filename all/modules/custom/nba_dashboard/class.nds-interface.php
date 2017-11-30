<?php

	class ndsInterface {
		
		private $esServer;
		private $esPath;
		private $handle;
		private $query;
		private $requestTpl = "http://%s/%s";
		private $request;
		private $rawResult;
		private $jsonResult;
		
		public function setEsSever( $esServer )
		{
			$this->esServer=$esServer;
		}

		public function getEsSever()
		{
			return $this->esServer;
		}
		
		public function setEsPath( $esPath )
		{
			$this->esPath=ltrim($esPath,'/ ');
			
		}

		public function getEsPath()
		{
			return $this->esPath;
		}
		
		public function setEsQuery( $query )
		{
			$this->query=$query;
		}
		
		public function setQueryHandle( $handle )
		{
			$this->handle=$handle;
		}
		
		public function getQueryQueu()
		{
			return $this->queryQueu;
		}

		public function resetQueryQueu()
		{
			$this->queryQueu=[];
		}

		public function prepareQuery()
		{
			$this->queryQueu[$this->handle]=[
				"request" => sprintf( $this->requestTpl, $this->getEsSever(), $this->getEsPath() ),
				"query" => $this->getEsQuery()
			];
		}

		public function getEsQuery()
		{
			return $this->query;
		}

		public function run()
		{
			try
			{
				$this->doChecks();
				$this->runRequests();
				$this->parseResults();
			} 
			catch (Exception $e)
			{
				echo 'caught exception: ',  $e->getMessage(), "\n";
				echo 'exiting';
			}
		}



		public function resultGetError( $handle )
		{
			return isset($this->queryQueu[$handle]['error']) ? $this->queryQueu[$handle]['error'] : null;
		}

		public function resultGetTotal( $handle )
		{
			return isset($this->queryQueu[$handle]['JSONresponse']['hits']['total']) ? $this->queryQueu[$handle]['JSONresponse']['hits']['total'] : null;
		}

		public function resultGetHits( $handle )
		{
			return isset($this->queryQueu[$handle]['JSONresponse']['hits']['hits']) ? $this->queryQueu[$handle]['JSONresponse']['hits']['hits'] : null;
		}
	
		public function resultGetAggregations( $handle )
		{
			return isset($this->queryQueu[$handle]['JSONresponse']['aggregations']) ? $this->queryQueu[$handle]['JSONresponse']['aggregations'] : null;
		}
	
		public function resultGetTimeTaken( $handle )
		{
			return isset($this->queryQueu[$handle]['JSONresponse']['took']) ? $this->queryQueu[$handle]['JSONresponse']['took'] : null;
		}

		public function resultRawResponse( $handle )
		{
			return isset($this->queryQueu[$handle]['response']) ? $this->queryQueu[$handle]['response'] : null;
		}

		public function resultParsedResponse( $handle )
		{
			return isset($this->queryQueu[$handle]['JSONresponse']) ? $this->queryQueu[$handle]['JSONresponse'] : null;
		}
		
		public function isHandleRegistered( $handle )
		{
			return isset($this->queryQueu[$handle]);
		}
		

		private function doChecks()
		{
			if (empty($this->getEsSever()))  throw new Exception('no server set');
			if (empty($this->getEsPath())) throw new Exception('no path set');
			//if (empty($this->getEsQuery())) throw new Exception('no query set');
			if (empty($this->getQueryQueu())) throw new Exception('no queries set');

		}

		private function translateJSONerror( $error )
		{
			$errors=[
				JSON_ERROR_NONE => 'No error has occurred',
				JSON_ERROR_DEPTH => 'The maximum stack depth has been exceeded',
				JSON_ERROR_STATE_MISMATCH => 'Invalid or malformed JSON',
				JSON_ERROR_CTRL_CHAR => 'Control character error, possibly incorrectly encoded',
				JSON_ERROR_SYNTAX => 'Syntax error',
				JSON_ERROR_UTF8 => 'Malformed UTF-8 characters, possibly incorrectly encoded',
				JSON_ERROR_RECURSION => 'One or more recursive references in the value to be encoded',
				JSON_ERROR_INF_OR_NAN => 'One or more NAN or INF values in the value to be encoded',
				JSON_ERROR_UNSUPPORTED_TYPE => 'A value of a type that cannot be encoded was given',
				JSON_ERROR_INVALID_PROPERTY_NAME => 'A property name that cannot be encoded was given',
				JSON_ERROR_UTF16 => 'Malformed UTF-16 characters, possibly incorrectly encoded',
			];
			
			return isset($errors[$error]) ? $errors[$error] : $error;
		}
		
		private function runRequests()
		{
			foreach((array)$this->getQueryQueu() as $key=>$val)
			{
				$this->queryQueu[$key]["cUrlHandle"]=curl_init();
				curl_setopt($this->queryQueu[$key]["cUrlHandle"], CURLOPT_URL,$val["request"]);
				curl_setopt($this->queryQueu[$key]["cUrlHandle"], CURLOPT_RETURNTRANSFER, true);
				curl_setopt($this->queryQueu[$key]["cUrlHandle"], CURLOPT_TIMEOUT, 10);
				curl_setopt($this->queryQueu[$key]["cUrlHandle"], CURLOPT_POST, true);
				curl_setopt($this->queryQueu[$key]["cUrlHandle"], CURLOPT_HTTPHEADER, [ "content-type: application/x-www-form-urlencoded; charset=UTF-8" ]);
				curl_setopt($this->queryQueu[$key]["cUrlHandle"], CURLOPT_POSTFIELDS,$val["query"]);
			}

			$mh = curl_multi_init();
			foreach((array)$this->getQueryQueu() as $key=>$val)
			{
				curl_multi_add_handle($mh,$val["cUrlHandle"]);
			}
			
			$running = null;

			do {
				curl_multi_exec($mh, $running);
			} while ($running);

			foreach((array)$this->getQueryQueu() as $key=>$val)
			{
				$this->queryQueu[$key]["response"]=curl_multi_getcontent($val["cUrlHandle"]);
				curl_multi_remove_handle($mh, $val["cUrlHandle"]);
			}

			curl_multi_close($mh);
		}
		
		private function parseResults()
		{
			foreach((array)$this->getQueryQueu() as $key=>$val)
			{
				if (empty($val['response']))
				{
					$this->queryQueu[$key]['error']= 'empty response';
				}
				else
				{
					$r=json_decode($val['response'],true);

					if (json_last_error() != JSON_ERROR_NONE)
					{
						$this->queryQueu[$key]['error']= 'invalid json: ' . $this->translateJSONerror( json_last_error() );
					}
					else
					{
						$this->queryQueu[$key]['JSONresponse']=$r;
			
						if (isset($r['error']))
						{
							$this->queryQueu[$key]['error']='elasticsearch error: ' .  $r['error']['reason'];
						}						
					}
				}
			}
		}
    }