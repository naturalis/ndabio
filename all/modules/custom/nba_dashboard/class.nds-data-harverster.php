<?php

	class ndsDataHarvester {
		
		private $cfg;
		private $services;
		private $queries;
		private $nds;
		private $data;

		public function __construct()
		{
			$this->cfg=new StdClass;
		}

		public function initialize()
		{
			if ( is_null($this->cfg->server)) die( "no server set" );
			if ( is_null($this->nds)) die( "no nds interface set" );
			
			$this->initConfig();
			$this->initServices();
			$this->initQueries();

			$this->nds->setEsSever( $this->cfg->server );
			$this->nds->resetQueryQueu();
		}

		public function setServer( $server )
		{			
			//$this->cfg->server='145.136.242.167:9200';
			//$this->cfg->server='localhost:44444';
			$this->cfg->server=trim(stri_replace('http://','',$server)," /");
		}

		public function setNdsInterface( $nds )
		{			
			$this->nds=$nds;
		}
		
		public function runQueries()
		{			
			$this->nds->run();
			$this->setData();
		}
			
		public function getData()
		{			
			return $this->data;
		}

		private function initConfig()
		{
			$this->cfg->dutchlands=
				[ "Netherlands",
				  "Nederland",
				  "NETHERLANDS",
				  "Holland",
				  "Ned",
				  "Netherlands, North Sea",
				  "Nederland en België",
				  "Ned.",
				  "Nederland; België",
				  "Netherlands (prob.)",
				  "West Nederland",
				  "The Netherlands",
				  "Country code: NL",
				  "Nederl.",
				  "NEDERLAND",
				  "NETHERLANDS-",
				  "Netherlands  (prob.)",
				  "Nederland (Z-H)",
				  "Netherlands, Waddenzee",
				  "NEDELRAND",
				  "NL.",
				  "Netherlands ?",
				  "\"Netherlands\"",
				  "Netherlands, Dutch coast",
				  "The Nertherlands",
				  "The Nethrlands",
				  "NEDERLAND-Z.",
				  "Nederlandse kust",
				  "Amsterdam",
				  "NETHERLANDS ?",
				  "Nederl",
				  "Netherlands, Dutch beaches",
				  "Netherlands, Noordzee",
				  "Netherlans",
				  "(Nederland)",
				  "NEDERLAND-",
				  "NEDERLAND-O.",
				  "Nederland & België",
				  "Nederland (N.L.)",
				  "Nederland (ZH)",
				  "Nederland / Belgie",
				  "Nederland?",
				  "Netherlands/Germany" ];

			//$this->cfg->subspeciesetceteras=[ "species", "subspecies", "var.", "subsp", "forma", "cv.", "f.", "subvar."];
			$this->cfg->subspeciesetceteras=[ "species", "subspecies", "subsp", "ssp." ];

		}

		public function prepareQueries()
		{			
			$this->prepareQuery( "totSpecimen", $this->services->specimen, $this->queries->emptyQuery );
			$this->prepareQuery( "totTaxon", $this->services->taxon, $this->queries->emptyQuery );
			$this->prepareQuery( "totMultiMedia", $this->services->multimedia, $this->queries->emptyQuery );
			$this->prepareQuery( "aggGroupByTaxonRank", $this->services->taxon, $this->queries->taxon['aggGroupByTaxonRank'] );
			$this->prepareQuery( "aggCollectionTypes", $this->services->specimen, $this->queries->specimen['aggCollectionTypes'] );
			//$this->prepareQuery( "aggRecordBasisPerCollectionTypes", $this->services->specimen, $this->queries->specimen['aggRecordBasisPerCollectionTypes'] );
			$this->prepareQuery( "aggTypeStatusPerCollectionTypes", $this->services->specimen, $this->queries->specimen['aggTypeStatusPerCollectionTypes'] );
			$this->prepareQuery( "aggVernacularNamesCardinality", $this->services->taxon, $this->queries->taxon['aggVernacularNamesCardinality'] );
			$this->prepareQuery( "aggAcceptedNamesCardinality", $this->services->taxon, $this->queries->taxon['aggAcceptedNamesCardinality'] );
			$this->prepareQuery( "aggSynonymCardinality", $this->services->taxon, $this->queries->taxon['aggSynonymCardinality'] );
			$this->prepareQuery( "aggAcceptedNamesCardinalitySpecimen", $this->services->specimen, $this->queries->specimen['aggAcceptedNamesCardinality'] );
			$this->prepareQuery( "aggCollectionTypeCountPerGatheringPerson", $this->services->specimen, $this->queries->specimen['aggCollectionTypeCountPerGatheringPerson'] );
			//$this->prepareQuery( "aggSpecimenPerScientificName", $this->services->specimen, $this->queries->specimen['aggSpecimenPerScientificName'] );
			$this->prepareQuery( "aggSpecimenPerScientificName", $this->services->specimen, str_replace('%SUBSPECIESETCRANKS%', '"' . implode('","',array_map(function($a) { return addslashes($a);} ,$this->cfg->subspeciesetceteras)) . '"', $this->queries->specimen['aggSpecimenPerScientificName_PREP']) );
//			$this->prepareQuery( "aggSpecimenCountPerCountryNotNL", $this->services->specimen, str_replace('%DUTCHLANDS%', '"' . implode('","',array_map(function($a) { return addslashes($a);} ,$this->cfg->dutchlands)) . '", ', $this->queries->specimen['aggSpecimenCountPerCountryNotNL_PREP']) );
			$this->prepareQuery( "aggSpecimenCountPerCountryNotNL", $this->services->specimen, $this->queries->specimen['aggSpecimenCountPerCountryNotNL_PREP'] );
			$this->prepareQuery( "aggSpecimenCountPerProvinceNL", $this->services->specimen, str_replace('%DUTCHLANDS%', '"' . implode('","',array_map(function($a) { return addslashes($a);} ,$this->cfg->dutchlands)) . '", ', $this->queries->specimen['aggSpecimenCountPerProvinceNL_PREP']) );
		}

		
		private function initServices()
		{
			$this->services=new StdClass;

			$this->services->taxon='/taxon/_search';
			$this->services->specimen='/specimen/_search';
			$this->services->multimedia='/multimedia/_search';
		}

		private function initQueries()
		{
			$this->queries=new StdClass;

			$this->queries->emptyQuery='{}';

			$this->queries->taxon=[];
			$this->queries->taxon['aggGroupByTaxonRank']='{ "size": 0, "aggs": { "aggGroupByTaxonRank": { "terms": { "field": "taxonRank" } } } }';
			$this->queries->taxon['aggVernacularNamesCardinality']='{ "size" : 0, "query": { "nested": { "path": "vernacularNames", "query": { "exists" : { "field" : "vernacularNames.name" } } } }, "ext" : { }, "aggs" : { "vernacularName": { "nested": { "path": "vernacularNames" }, "aggs": { "vernacularName": { "cardinality" : { "field" : "vernacularNames.name" }}}}}}';
			$this->queries->taxon['aggAcceptedNamesCardinality']='{ "size" : 0, "query": { "exists" : { "field" : "acceptedName.fullScientificName" } }, "ext" : { }, "aggs": { "acceptedName": { "cardinality" : { "field" : "acceptedName.fullScientificName" } } }}';
			$this->queries->taxon['aggSynonymCardinality']='{ "size" : 0, "query": { "nested": { "path": "synonyms", "query": { "exists" : { "field" : "synonyms.fullScientificName" } } } }, "ext" : { }, "aggs" : { "synonym": { "nested": { "path": "synonyms" }, "aggs": { "synonym": { "cardinality" : { "field" : "synonyms.fullScientificName" } } } } }}';

			$this->queries->specimen=[];
			$this->queries->specimen['aggCollectionTypes']='{ "size" : 0, "ext" : {}, "aggs" : { "collectionType" : { "terms" : { "field" : "collectionType", "size": 10 } } } }';
			$this->queries->specimen['aggTypeStatusPerCollectionTypes']='{ "size" : 0, "query" : { "nested": { "path": "identifications", "query": { "exists" : { "field" : "identifications.typeStatus" } } } }, "ext" : {}, "aggs" : { "collectionType" : {"terms" : { "field" : "collectionType", "size": 100 },"aggs" : {"identifications" : {"nested": {"path": "identifications"},"aggs" : {"typeStatus" : {"terms" : { "field" : "identifications.typeStatus", "size": 100 }}}}}}}}';
			$this->queries->specimen['aggRecordBasisPerCollectionTypes']='{"size" : 0,"query": {"exists" : { "field" : "recordBasis" }},"ext" : {},"aggs" : {"collectionType" : {"terms" : { "field" : "collectionType", "size": 100 },"aggs" : {"recordBasis" : {"terms" : { "field" : "recordBasis", "size": 100 }}}}}}';
			$this->queries->specimen['aggAcceptedNamesCardinality']='{ "size" : 0, "query": { "nested": { "path": "identifications", "query": { "exists" : { "field" : "identifications.scientificName.fullScientificName" } } } }, "ext" : { }, "aggs" : { "fullScientificName": { "nested": { "path": "identifications" }, "aggs": { "fullScientificName": { "cardinality" : { "field" : "identifications.scientificName.fullScientificName" }}}}}}';
			$this->queries->specimen['aggCollectionTypeCountPerGatheringPerson']='{ "size" : 0, "query": { "nested": { "path": "gatheringEvent.gatheringPersons", "query": { "exists" : { "field" : "gatheringEvent.gatheringPersons.fullName" } } } }, "ext" : { }, "aggs" : { "gatheringPersons": { "nested": { "path": "gatheringEvent.gatheringPersons" }, "aggs": { "gatheringPersons": { "terms" : { "field" : "gatheringEvent.gatheringPersons.fullName","exclude": ["Unknown","Unreadable"], "order": { "_count": "desc" }, "size": 2000 }, "aggs": { "collectionType": { "reverse_nested": {}, "aggs" : { "collectionType_count" : { "cardinality" : { "field" : "collectionType" } } } } } } } } }}';
			$this->queries->specimen['aggGatheringPersonCollectionTypeCount_PREP']='{ "size" : 0, "query": { "nested": { "path": "gatheringEvent.gatheringPersons", "query": { "term": { "gatheringEvent.gatheringPersons.fullName": { "value": "%COLLECTOR%" } } } }}, "ext" : { }, "aggs" : { "collectionType_count" : { "terms" : { "field" : "collectionType", "size" : 20 } } } }';
//			$this->queries->specimen['aggSpecimenPerScientificName']='{ "size" : 0, "query": { "nested": { "path": "identifications", "query": { "exists" : { "field" : "identifications.scientificName.fullScientificName" } } } }, "aggs": { "fullScientificName": { "nested": { "path": "identifications" }, "aggs": { "fullScientificName": { "terms": {"field" : "identifications.scientificName.fullScientificName","exclude": ["?"]} } } } }}';
			$this->queries->specimen['aggSpecimenPerScientificName_PREP']='{ "size" : 0, "query": { "nested": { "path": "identifications", "query": { "bool": { "must": [ { "exists" : { "field" : "identifications.scientificName.fullScientificName" } }, { "terms": { "identifications.taxonRank": [ %SUBSPECIESETCRANKS% ] } } ] } } } }, "aggs": { "fullScientificName": { "nested": { "path": "identifications" }, "aggs": { "fullScientificName": { "terms": {"field" : "identifications.scientificName.fullScientificName", "exclude": ["?"], "size" : 15} } } } }}';	
//			$this->queries->specimen['aggSpecimenCountPerCountryNotNL_PREP']='{ "size" : 0, "query": { "bool": { "must_not": [ { "terms": { "gatheringEvent.country": [ %DUTCHLANDS% "Unknown" ] } } ] } }, "aggs": { "country": { "terms": {"field" : "gatheringEvent.country", "size" : 100 } } }}';
			$this->queries->specimen['aggSpecimenCountPerCountryNotNL_PREP']='{ "size" : 0, "query": { "bool": { "must_not": [ { "terms": { "gatheringEvent.country": [ "Unknown" ] } } ] } }, "aggs": { "country": { "terms": {"field" : "gatheringEvent.country", "size" : 100 } } }}';
			$this->queries->specimen['aggSpecimenCountPerProvinceNL_PREP']='{ "size" : 0, "query": { "bool": { "must": [ { "terms": { "gatheringEvent.country": [ %DUTCHLANDS% "Unknown" ] } } ] } }, "aggs": { "country": { "terms": {"field" : "gatheringEvent.provinceState"} } }}';
		}

		private function prepareQuery( $handle, $service, $query )
		{
			$this->nds->setEsPath( $service );
			$this->nds->setEsQuery( $query );
			$this->nds->setQueryHandle( $handle );
			$this->nds->prepareQuery();
		}
	
		private function setData()
		{
			$this->data=new StdClass;
		
			if ($this->nds->isHandleRegistered( "totSpecimen" )) $this->data->totSpecimen = $this->nds->resultGetTotal( "totSpecimen" );
			if ($this->nds->isHandleRegistered( "totTaxon" )) $this->data->totTaxon = $this->nds->resultGetTotal( "totTaxon" );
			if ($this->nds->isHandleRegistered( "totMultiMedia" )) $this->data->totMultiMedia = $this->nds->resultGetTotal( "totMultiMedia" );
			if ($this->nds->isHandleRegistered( "aggGroupByTaxonRank" )) $this->data->aggGroupByTaxonRank = $this->nds->resultGetAggregations( "aggGroupByTaxonRank" );
			if ($this->nds->isHandleRegistered( "aggCollectionTypes" )) $this->data->aggCollectionTypes = $this->nds->resultGetAggregations( "aggCollectionTypes" );
			if ($this->nds->isHandleRegistered( "aggRecordBasisPerCollectionTypes" )) $this->data->aggRecordBasisPerCollectionTypes = $this->nds->resultGetAggregations( "aggRecordBasisPerCollectionTypes" );
			if ($this->nds->isHandleRegistered( "aggTypeStatusPerCollectionTypes" )) $this->data->aggTypeStatusPerCollectionTypes = $this->nds->resultGetAggregations( "aggTypeStatusPerCollectionTypes" );
			if ($this->nds->isHandleRegistered( "aggVernacularNamesCardinality" )) $this->data->aggVernacularNamesCardinality = $this->nds->resultGetAggregations( "aggVernacularNamesCardinality" );
			if ($this->nds->isHandleRegistered( "aggAcceptedNamesCardinality" )) $this->data->aggAcceptedNamesCardinality = $this->nds->resultGetAggregations( "aggAcceptedNamesCardinality" );
			if ($this->nds->isHandleRegistered( "aggSynonymCardinality" )) $this->data->aggSynonymCardinality = $this->nds->resultGetAggregations( "aggSynonymCardinality" );
			if ($this->nds->isHandleRegistered( "aggAcceptedNamesCardinalitySpecimen" )) $this->data->aggAcceptedNamesCardinalitySpecimen = $this->nds->resultGetAggregations( "aggAcceptedNamesCardinalitySpecimen" );
			if ($this->nds->isHandleRegistered( "aggSpecimenPerScientificName" )) $this->data->aggSpecimenPerScientificName = $this->nds->resultGetAggregations( "aggSpecimenPerScientificName" );
			if ($this->nds->isHandleRegistered( "aggSpecimenCountPerCountryNotNL" )) $this->data->aggSpecimenCountPerCountryNotNL = $this->nds->resultGetAggregations( "aggSpecimenCountPerCountryNotNL" );
			if ($this->nds->isHandleRegistered( "aggSpecimenCountPerProvinceNL" )) $this->data->aggSpecimenCountPerProvinceNL = $this->nds->resultGetAggregations( "aggSpecimenCountPerProvinceNL" );
			if ($this->nds->isHandleRegistered( "aggCollectionTypeCountPerGatheringPerson" )) $this->data->aggCollectionTypeCountPerGatheringPerson = $this->aggCollectionTypeCountPerGatheringPerson();
		}
		
		private function aggCollectionTypeCountPerGatheringPerson()
		{
			$d=$this->nds->resultGetAggregations( "aggCollectionTypeCountPerGatheringPerson" );
			
			if (empty($d)) return;
			
			$b=[];

			foreach((array)$d['gatheringPersons']['gatheringPersons']['buckets'] as $val)
			{
				$b[]=['collector'=>$val['key'],'collection_count'=>$val['collectionType']['collectionType_count']['value'],'collections'=>[]];
			}
			
			usort($b,function($a,$b)
			{ 
				if ($a['collection_count']==$b['collection_count']) { return $a['collector']<$b['collector']; } else { return $a['collection_count']<$b['collection_count']; }
			});
			
			$b=array_slice($b,0,10);
			
			$c=new ndsInterface;
			$c->setEsSever( $this->cfg->server );
			$c->resetQueryQueu();
				
			foreach((array)$b as $key=>$val)
			{
				$c->setEsPath( $this->services->specimen );
				$c->setEsQuery( str_replace('%COLLECTOR%',$val['collector'],$this->queries->specimen['aggGatheringPersonCollectionTypeCount_PREP']) );
				$c->setQueryHandle( "aggGatheringPersonCollectionTypeCount_" . $key );
				$c->prepareQuery();			
			}
			
			$c->run();
			
			foreach((array)$b as $key=>$val)
			{
				$s = $c->resultGetAggregations( "aggGatheringPersonCollectionTypeCount_" . $key );
			
				foreach((array)$s['collectionType_count']['buckets'] as $val2)
				{
					$b[$key]['collections'][]=['collection'=>$val2['key'],'doc_count'=>$val2['doc_count']];
				}
			}

			return $b;
		}

	}
