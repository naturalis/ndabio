<?php

	include_once("class.nds-interface.php");
	include_once("class.nds-data-harverster.php");
	
/*
<script src="js/jquery-3.2.1.min.js" type="text/javascript"></script>
<script src="js/Chart.js"></script>
<script src="js/jqvmap/jquery.vmap.js"></script>
<script src="js/jqvmap/maps/jquery.vmap.world.js"></script>
<link rel="stylesheet" type="text/css" href="css/style.css">

	to do:
	<ul>
		<li>change block titles and add explanaroty texts</li>
		<li>dutch map that actually works</li>
		<li>use same map-class for world & nl (and introduce tooltips etc.)</li>
		<li>separate sections for siebld & dubois</li>
		<li>specimen tree (based on CoL taxonomy, greyed out when no specimen, tooltip for speciment lists)</li>
		<li>complete taxonrank list for "what constitutes a (sub)species?"</li>
		<li>re-examine collectors (odd behaviour when only one or two collections)</li>
		<li>storage units!</li>
		<li>add legends to graphs</li>
		<li>post-processing:
			<ul>
				<li>harmonize countries</li>
				<li>logical collection-groupings</li>
				<li>harmonize collectors' names (but how?)</li>
			</ul>
		</li>
		<li>extra charts:
			<ul>
				<li>subdivision for botany?</li>
				<li>subdivision for collections as double-banded donut</li>
				<li>specimen over time, stacked per colletion</li>
				<li>something useful that can be expressed in a bar chart</li>
				<li>something useful that can be expressed in a radar plot (because they are cool)</li>
			</ul>
		</li>
	</ul>

*/

	$tpl=new StdClass;
	$tpl->singleNumberTable='<table class="single-number-table"><tr><th>%LABEL%</th></tr><tr><td class="number">%DATA%</td></tr></table>';
	$tpl->noColorTextTable='<table class="no-color"><tr><th>%LABEL%</th></tr><tr><td>%DATA%</td></tr></table>';
	$tpl->column='<div class="left-float">%ROW%</div>';
	$tpl->row='<div id="r%ID%">%COLS%</div>';

	/*
	$iso3166 = [
		"Netherlands" => "NL",
		"NETHERLANDS" => "NL",
		"Indonesia" => "ID",
		"France" => "FR",
		"Papua New Guinea" => "PG",
		"Australia" => "AU",
		"Germany" => "DE",
		"Brazil" => "BR",
		"Philippines" => "PH",
		"United States of America" => "US",
		"Thailand" => "TH",
		"Malaysia/Sabah" => "MY",
		"Spain" => "ES",
		"Cameroon" => "CM",
		"South Africa" => "ZA",
		"Gabon" => "GA",
		"Switzerland" => "CH",
		"Nederland" => "NL",
		"Suriname" => "SR",
		"India" => "IN",
		"Italy" => "IT",
		"Japan" => "JP",
		"Algeria" => "DZ",
		"Argentina" => "AR",
		"Austria" => "AT",
		"Belgium" => "BE",
		"Benin" => "BJ",
		"Bolivia" => "BO",
		"Brunei" => "BN",
		"Burundi" => "BI",
		"Cabo Verde" => "CV",
		"Canada" => "CA",
		"Chile" => "CL",
		"China" => "CN",
		"Colombia" => "CO",
		"Congo (Kinshasa)" => "CD",
		"Costa Rica" => "CR",
		"Cuba" => "CU",
		"Denmark" => "DK",
		"Ecuador" => "EC",
		"Egypt" => "EG",
		"Ethiopia" => "ET",
		"Finland" => "FI",
		"French Guiana" => "GF",
		"Ghana" => "GH",
		"Greece" => "GR",
		"Guinea" => "GN",
		"Guyana" => "GY",
		"Hungary" => "HU",
		"Ireland" => "IE",
		"Ivory Coast" => "CI",
		"Jamaica" => "JM",
		"Kenya" => "KE",
		"Liberia" => "LR",
		"Madagascar" => "MG",
		"Malawi" => "MW",
		"Malaysia" => "MY",
		"Malta" => "MT",
		"Mexico" => "MX",
		"Morocco" => "MA",
		"Mozambique" => "MZ",
		"Namibia" => "NA",
		"New Caledonia" => "NC",
		"New Zealand" => "NZ",
		"Nigeria" => "NG",
		"Norway" => "NO",
		"Oman" => "OM",
		"Panama" => "PA",
		"Paraguay" => "PY",
		"Peru" => "PE",
		"Poland" => "PL",
		"Portugal" => "PT",
		"Puerto Rico" => "PR",
		"Romania" => "RO",
		"Solomon Islands" => "SB",
		"Sri Lanka" => "LK",
		"Surinam" => "SR",
		"Sweden" => "SE",
		"Taiwan" => "TW",
		"Tanzania" => "TZ",
		"Turkey" => "TR",
		"United Kingdom" => "UK",
		"United States" => "US",
		"Venezuela" => "VE",
		"Vietnam" => "VN",
		"Yugoslavia (Former)" => "RS",
		"U.S.A." => "US",
		"SPAIN" => "SP",
		"Russija" => "RU",
		"Nederlandse Antillen" => "NL",
		"INDONESIA" => "ID",
		"JAPAN" => "JP",
		"Hawaii (USA)" => "US",
		"FRANCE" => "FR",
		"GERMANY" => "DE",
		"España" => "SP",
		"Ellás" => "GR",
		"Deutschland" => "GR",
		"Bonaire, Saint Eustatius" => "NL",
		"Curaçao" => "NL",
		"Canary Islands (Spain)" => "SP",
		"Malaysia/Sarawak" => "MY",
		"Malaysia/Malaya" => "MY"
	];
	
	*/

	function renderData( $data )
	{
		global  $tpl;
	
		$rows=[];
		$cols=[];
		$cells=[];

		$cells[]=str_replace(['%LABEL%','%DATA%'],[t('Totaal aantal specimen'),$data->totSpecimen],$tpl->singleNumberTable);
		$cells[]=str_replace(['%LABEL%','%DATA%'],[t('Totaal aantal taxa'),$data->totTaxon],$tpl->singleNumberTable);
		$cells[]=str_replace(['%LABEL%','%DATA%'],[t('Totaal aantal multimedia'),$data->totMultiMedia],$tpl->singleNumberTable);

		$d='<ul>
				<li>Zoology and Geology catalogues: zoölogische, palaeontologische, mineralogische en petrologische specimen- en multimedia objecten</li>
				<li>Botany catalogues: botanische specimen- en multimedia objecten</li>
				<li>Nederlandse Soortenregister: taxonomische namenlijst en bijbehorende beschrijvingen en multimedia van in Nederland voorkomende soorten.</li>
			</ul>';

		$cells[]=str_replace(['%LABEL%','%DATA%'],[t('Bronnen van het Naturalis Biodiversity Center'),$d],$tpl->noColorTextTable);
		$cols[]=str_replace('%ROW%',implode("\n",$cells),$tpl->column);

		$cells=[];

		$rows[]=str_replace(['%ID%','%COLS%'],[count($rows),implode("\n",$cols)],$tpl->row);
		$cols=[];
		$cells=[];

		return implode("\n",$rows);
		
	}

    
/*       
    <div id="r1">
	    
        <div class="left-float">
	
			-> hier
    
            <table class="normal-table">
                <tr><th colspan="2">aggCollectionTypes (top 10)</th></tr>
                <tr><td class="pie" colspan="2"><canvas id="aggCollectionTypes" width="300" height="300"></canvas></td></tr>
                <?php
                
                    foreach((array)$data->aggCollectionTypes['collectionType']['buckets'] as $bucket)
                    {
                        echo '<tr><td>' . $bucket['key'] . '</td><td class="number">' . $bucket['doc_count'] . '</td></tr>';
                    }
                ?>
            </table>
			<script>
            <?php
            foreach((array)$data->aggCollectionTypes['collectionType']['buckets'] as $key=>$bucket)
            {
                echo "aggCollectionTypesData.push({label:'" . $bucket['key'] . "',value:" . $bucket['doc_count'] . ", color: defaultColors[".$key."] });\n";
            }
            ?>
            </script>    
        </div>

        <div class="left-float">
            <table class="normal-table no-color">
                <tr><td>
                <img src="img/partner_kaart_blanko.gif" id="netherlands-map" />
                <!-- div id="aggSpecimenCountPerProvinceNL" style="width:375px; height: 450px;"></div -->
                </td></tr>
            </table>
    
            <table class="normal-table">
                <tr><th colspan="2">aggSpecimenCountPerProvinceNL</th></tr>
                <tr><td colspan="2" class="info main">what am i looking at here?</td></tr>
                <?php
                
                    foreach((array)$data->aggSpecimenCountPerProvinceNL['country']['buckets'] as $bucket)
                    {
                        echo '<tr><td>' . $bucket['key'] . '</td><td class="number">' . $bucket['doc_count'] . '</td></tr>';
                    }
                ?>

                <tr><th colspan="2"><canvas id="aggSpecimenCountPerProvinceNL" width="300" height="300"></canvas></th></tr>
                <tr><td colspan="2" class="info secondary">more extra info</td></tr>
            </table>
			<script>
            <?php
            foreach((array)$data->aggSpecimenCountPerProvinceNL['country']['buckets'] as $key=>$bucket)
            {
                echo "aggSpecimenCountPerProvinceNLData.push({label:'" . $bucket['key'] . "',value:" . $bucket['doc_count'] . ", color: defaultColors[".$key."] });\n";
            }
            ?>
            </script> 
        </div>

        <div class="left-float">
            <table class="double-table">
                <tr><th colspan="2">aggTypeStatusPerCollectionTypes<br />(top 5 > top 10)</th></tr>
                <tr><td colspan="2" class="info main">what am i looking at here?</td></tr>
                <?php
                
                    $b=array_slice($data->aggTypeStatusPerCollectionTypes['collectionType']['buckets'],0,5);
                
                    foreach((array)$b as $collectionType)
                    {
                        echo '<tr class="main-item"><td colspan="2">' . $collectionType['key'] . ' (<span class="number">' . $collectionType['doc_count'] . '</span>)</tr>';
                        
                        $c=array_slice($collectionType['identifications']['typeStatus']['buckets'],0,10);
        
                        foreach((array)$c as $typeStatus)
                        {
                            echo '<tr class="sub-item"><td>' . $typeStatus['key'] . '</td><td class="number">' . $typeStatus['doc_count'] . '</td></tr>';
            
                        }
                    }
                ?>
            </table>
        </div>
    
	</div>
    
    <br clear="all" />

    <div id="r2">

        <div class="left-float">
            <?php $countryCutOff=20; ?>
    
            <table class="normal-table">
                <tr><th colspan="2">aggSpecimenCountPerCountryNotNL (top <?php echo $countryCutOff; ?>)</th></tr>
                <?php
                    $codes=[];
                    foreach((array)$data->aggSpecimenCountPerCountryNotNL['country']['buckets'] as $key=>$bucket)
                    {
                        if(isset($iso3166[$bucket['key']]))
                        {
                            $code=$iso3166[$bucket['key']];
                            if (isset($codes[$code]))
                                $codes[$code]+=$bucket['doc_count'];
                            else
                                $codes[$code]=$bucket['doc_count'];
                        }
    
                        if ($key==0 || $key>$countryCutOff) continue; 
                        echo '<tr><td>' . $bucket['key'] . '</td><td class="number">' . $bucket['doc_count'] . '</td></tr>';
                    }
                ?>
            </table>
        </div>
    
        <div class="left-float">
            <table class="wide-table no-color">
                <tr><td><div id="aggSpecimenCountPerCountryNotNL" style="width:600px; height:425px;"></div></td></tr>
            </table>
            <script>
            <?php
            foreach((array)$codes as $code=>$count)
            {
                echo "countryData." . strtolower($code) .'=' . $count . "\n";
            }
            ?>
            </script>                
            </div>
        </div>

	</div>

    <br clear="all" />

    <div id="r2-5">

        <div class="half-width text-block">
            some info
        </div>
            
        <div class="half-width text-block">
            some info
        </div>
        
	</div>
        
    <br clear="all" />

    <div id="r3">

        <div class="left-float">
            <table class="normal-table wide-table">
                <tr><th colspan="2">aggSpecimenPerScientificName (top 15)<br />(sub)species only</th></tr>
                <?php
                
                    foreach((array)$data->aggSpecimenPerScientificName['fullScientificName']['fullScientificName']['buckets'] as $bucket)
                    {
                        echo '<tr><td>' . $bucket['key'] . '</td><td class="number">' . $bucket['doc_count'] . '</td></tr>';
                    }
                ?>
            </table>
        </div>

        <div class="left-float">
            <table class="normal-table">
                <tr><th colspan="2">aggGroupByTaxonRank</th></tr>
                <?php
                
                    foreach((array)$data->aggGroupByTaxonRank['aggGroupByTaxonRank']['buckets'] as $bucket)
                    {
                        echo '<tr><td>' . $bucket['key'] . '</td><td class="number">' . $bucket['doc_count'] . '</td></tr>';
                    }
                ?>
            </table>

            <table class="single-number-table">
                <tr><th>aggAcceptedNamesCardinalitySpecimen<br />(unique in specimen)</th></tr>
                <tr><td class="number"><?php echo $data->aggAcceptedNamesCardinalitySpecimen['fullScientificName']['fullScientificName']['value']; ?></td></tr>
                <tr><td class="info main">what am i looking at here?<br /><a href="#">a link to somewhere intersting</a></td></tr>
            </table>
        </div>

    </div>
    
    <br clear="all" />

    <div id="r4">

        <div class="left-float">
            <table class="single-number-table">
                <tr><th>aggVernacularNamesCardinality</th></tr>
                <tr><td class="number"><?php echo $data->aggVernacularNamesCardinality['vernacularName']['vernacularName']['value']; ?></td></tr>
            </table>
        
            <table class="single-number-table">
                <tr><th>aggAcceptedNamesCardinality (taxon)</th></tr>
                <tr><td class="number"><?php echo $data->aggAcceptedNamesCardinality['acceptedName']['value']; ?></td></tr>
            </table>
        
            <table class="single-number-table">
                <tr><th>aggSynonymCardinality</th></tr>
                <tr><td class="number"><?php echo $data->aggSynonymCardinality['synonym']['synonym']['value']; ?></td></tr>
            </table>
        </div>

        <div class="left-float">
            <table class="double-table">
                <tr><th colspan="2">aggCollectionTypeCountPerGatheringPerson<br />(top 10)</th></tr>
                <?php
                
                    foreach((array)$data->aggCollectionTypeCountPerGatheringPerson as $key=>$collector)
                    {
                        echo '
                            <tr class="main-item">
                                <td colspan="2" onclick="$(\'.list'.$key.'\').toggle();" class="toggle">' . 
                                    '<span class="main-item">' . $collector['collector'] . '</span> (<span class="number">' . $collector['collection_count'] . '</span> collections)
                                </td>
                            </tr>';
                        
                        foreach((array)$collector['collections'] as $collection)
                        {
                            echo '<tr class="sub-item invisible list'.$key.'"><td>' . $collection['collection'] . '</td><td class="number">' . $collection['doc_count'] . '</td></tr>';
            
                        }
                    }				
                ?>
            </table>
        </div>

        <div class="left-float">
            <table class="no-color">
                <tr><th>BioPortal</th></tr>
                <tr><td>
Het BioPortal toont de kracht van de NBA. Het is een “klant” van de NBA, een voorbeeldapplicatie die de gegevens uit de NBA via een webportaal toegankelijk maakt. Via dit portaal kan iedereen, geïnteresseerde of wetenschapper, in de gegevensbronnen van Naturalis grasduinen, met simpele zoekopdrachten, via complexe queries of op basis van specifieke geografische locaties.
                </td></tr>
                <tr><td class="info"><a href="/">BioPortal</a></td></tr>
            </table>
        </div>
        
    </div>

    <br clear="all" />


<script>
$(document).ready(function(e)
{
	String.prototype.reverse = function() {	
		var o = '';
		for (var i = this.length - 1; i >= 0; i--)
		o += this[i];
		return o;
	}	

	$('.number').each(function(index, element)
	{
		$(this).html($(this).html().reverse().match(/.{1,3}/g).join(".").reverse());
    });
	

	var c1 = document.getElementById('aggCollectionTypes').getContext('2d');
	var aggCollectionTypesChart = new Chart(c1).Pie(aggCollectionTypesData	,{ animation: false });

	var c2 = document.getElementById('aggSpecimenCountPerProvinceNL').getContext('2d');
	var aggSpecimenCountPerProvinceNLChart = new Chart(c2).Pie(aggSpecimenCountPerProvinceNLData	,{ animation: false });

//	https://jqvmap.com/
//	https://github.com/manifestinteractive/jqvmap

	jQuery('#aggSpecimenCountPerCountryNotNL').vectorMap({
		map: 'world_en',
		backgroundColor: null,
		color: '#ffffff',
		hoverOpacity: 0.7,
		selectedColor: '#666666',
		enableZoom: true,
		showTooltip: true,
		values: countryData,
		scaleColors: ['#C8EEFF', '#006491'],
		normalizeFunction: 'polynomial',
	});
});

</script>

</body>
</html>

*/
	function getCollectorData( $esServer )
	{
		$n=new ndsDataHarvester;
		$n->setServer( $esServer  );
		$n->setNdsInterface( new ndsInterface );
		$n->initialize();
		$n->prepareQueries();
		$n->runQueries();

		return  renderData( $n->getData() );
	}


	
	


	