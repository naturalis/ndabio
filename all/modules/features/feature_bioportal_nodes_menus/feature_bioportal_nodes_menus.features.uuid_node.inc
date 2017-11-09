<?php
/**
 * @file
 * feature_bioportal_nodes_menus.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function feature_bioportal_nodes_menus_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'title' => 'About',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'en',
  'created' => 1493645348,
  'tnid' => 3796,
  'translate' => 0,
  'uuid' => '046583ea-ed92-4f82-9641-f2821bea952a',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The BioPortal is a website that serves as the national access portal for all information relating to natural history, from basic data about museum objects to fully illustrated species descriptions. Via a single website, BioPortal grants access to all digitized details of the Naturalis collections, using the Netherlands Biodiversity API (NBA). Per October 2017 already more than 8 Million objects&nbsp; are included and the information is continuously extended. The NBA links the data to various digital sources of guaranteed scientific&nbsp; quality. This allows to consult these data through one single website.</p>

<p>Via the NBA, BioPortal can access the following data sources</p>

<ul>
	<li>Brahms: botanical specimen data at Naturalis;</li>
	<li>Naturalis Collectieregistragiesysteem (CRS): zoological, paleontological, mineralogical and petrological specimen data of&nbsp;Naturalis;</li>
	<li><a href="http://www.nederlandsesoorten.nl/content/english">Dutch Species Register:</a> list and descriptions of all species that occur in the Netherlands;</li>
	<li><a href="http://www.catalogueoflife.org/" target="_blank">Catalogue of Life</a>: index of names of all known species of the world</li>
</ul>

<p>We call this collection of data the NDS: the Naturalis Data Store. The data is fed into this store through an ETL-process that harmonizes several different data formats into a single, ABCD-compatible document model.</p>

<p>The BioPortal reflects the strength of the NBA. It is effectively a ‘client’ of the NBA, an example application that delivers data from the NBA in an appealing manner, via a web portal. By means of this portal, anyone – from the interested amateur to the research scientist – can carry out full-text searches or simply graze through the data using specific fields and geographical locations.</p>

<p>Special Naturalis collections are highlighted in the portal, directly accessible in the section \'Explore highlights\'.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-05-01 13:29:08 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'NBA Import',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'en',
  'created' => 1508239089,
  'tnid' => 3818,
  'translate' => 0,
  'uuid' => '1d6d1ba0-c144-4609-8f0f-f516577d5fa7',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<table border="0" cellpadding="1" cellspacing="1">
	<tbody>
		<tr>
			<td><strong>Naturalis Botany catalogues</strong></td>
			<td style="text-align:right; white-space:nowrap">October 12th, 2017</td>
		</tr>
		<tr>
			<td><strong>Naturalis Zoology and Geology catalogues</strong></td>
			<td style="text-align:right; white-space:nowrap">October 14th, 2017</td>
		</tr>
		<tr>
			<td><strong>Naturalis Storage Units</strong></td>
			<td style="text-align:right; white-space:nowrap">May 22nd, 2017</td>
		</tr>
		<tr>
			<td><strong>Cataologue of Life</strong></td>
			<td style="text-align:right; white-space:nowrap">April 2017</td>
		</tr>
		<tr>
			<td><strong>Dutch Species Register</strong></td>
			<td style="text-align:right; white-space:nowrap">October 14th, 2017</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-10-17 11:18:09 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Disclaimer',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'en',
  'created' => 1413896301,
  'tnid' => 1,
  'translate' => 0,
  'uuid' => '1dfa43fc-f62c-4d40-a016-4e4f40952954',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Every effort has been taken to ensure the accuracy of the information on bioportal.naturalis.nl.&nbsp;</h2>

<p>However, Naturalis Biodiversity Center excludes all and any liability for damage resulting from the use, in whatever manner, of information supplied on this site.</p>

<h2>Intellectual Property Rights</h2>

<p>Every effort has been taken to protect the interests of third parties when using data, texts and pictures. If, however, you believe that this site contains material that is subject to intellectual property rights, without agreements having been reached with the rightful owner, please contact the web editors (<a href="mailto:bioportal@naturalis.nl">bioportal@naturalis.nl</a>).</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-10-21 12:58:21 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'The Mammoth Collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500988713,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '228ef9ec-33dd-48e0-9f8c-6ef82789daa5',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Naturalis has one of the largest collection of woolly mammoth worldwide. de collection consists of ca. 9000 specimens. The majority is trawled up from the bottom of the North Sea. The collection is of course largely made up of large and heavy objects, but also the small details such as the first milk molar of a baby mammoth and the fragile hyoid are represented. <a href="http://www.naturalis.nl/nl/kennis/collectie/Verhalen-uit-Naturalis/mammoet-collectie/" target="_blank">More information</a> [Dutch]</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'mammoth',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:18:33 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'The Siebold Collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500543934,
  'tnid' => 3409,
  'translate' => 0,
  'uuid' => '27488ec8-d9fc-499b-98eb-c216a74c6ff1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The Siebold Collection of natural history objects includes a total of 200 mammals, 900 birds, 750 fishes, 170 reptiles, over 5,000 invertebrates, 2,000 different species of plants and 12,000 herbarium specimens. Many of these are stored in Naturalis\' collection depots and available in the BioPortal. The material was collected by Von Siebold&nbsp;between 1823 and 1829&nbsp;during his stay in Japan. The Siebold Collection was the first major collection of Japanese specimen in Europe and contained many species of plants and animals that were unknown in Europe at the time. <a href="https://www.naturalis.nl/nl/kennis/collectie/Verhalen-uit-Naturalis/siebold-de-collectie/" style="text-decoration:none;" target="_blank"><u>Read more</u></a> [Dutch]</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'siebold',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'skelet',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'ndabio_header_image',
  'language' => 'en',
  'created' => 1416470988,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '3250b7b0-0cde-4b3d-88f5-931e0bb1f83f',
  'field_ndabio_header_image' => array(),
  'date' => '2014-11-20 08:09:48 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Arts Collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500543934,
  'tnid' => 3406,
  'translate' => 0,
  'uuid' => '38a198b7-d5bf-49e1-9f95-d68a2d8615f6',
  'body' => array(),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'arts',
        'format' => NULL,
      ),
    ),
  ),
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Contact',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'nl',
  'created' => 1418588269,
  'tnid' => 6,
  'translate' => 0,
  'uuid' => '3e237a01-bd06-477b-a693-da1c7686f9f1',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Vragen en suggesties over BioPortal website</h2>

<table border="0" style="width:100%">
	<tbody>
		<tr>
			<td style="width:50%">E-mail</td>
			<td><a href="mailto:bioportal@naturalis.nl">bioportal@naturalis.nl</a></td>
		</tr>
	</tbody>
</table>

<h2>Vragen en suggesties over BioPortal content</h2>

<table border="0" style="width:100%">
	<tbody>
		<tr>
			<td style="width:50%">E-mail<br />
			Indien van toepassing, vermeld in het Onderwerp bron en collectienaam</td>
			<td style="vertical-align:top"><a href="mailto:collectie@naturalis.nl?subject=Bioportal content: [bron] [collectienaam]">collectie@naturalis.nl</a></td>
		</tr>
	</tbody>
</table>

<h2>Naturalis Biodiversity Center</h2>

<table border="0" style="width:100%">
	<tbody>
		<tr>
			<td style="width:50%">Museumadres</td>
			<td>Pesthuislaan 7,&nbsp;2333 AB&nbsp; Leiden</td>
		</tr>
		<tr>
			<td style="width:50%">Kantooradres (algemeen)</td>
			<td>Vondellaan 55, 2332 AA&nbsp; Leiden</td>
		</tr>
		<tr>
			<td style="width:50%">Kantoooradres (herbarium)</td>
			<td>Nieuwenhuizenweg 19, 2314 XP&nbsp; Leiden</td>
		</tr>
		<tr>
			<td>Postadres</td>
			<td>Postbus 9517, 2300 RA&nbsp; Leiden</td>
		</tr>
		<tr>
			<td>Telefoonnummer</td>
			<td>+31-(0)71-7519600</td>
		</tr>
		<tr>
			<td>E-mail</td>
			<td><a href="mailto:contact@naturalis.nl">contact@naturalis.nl</a></td>
		</tr>
	</tbody>
</table>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-12-14 20:17:49 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Help',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_help',
  'language' => 'nl',
  'created' => 1413895042,
  'tnid' => 2,
  'translate' => 0,
  'uuid' => '3fbad984-3780-4e5e-b2a9-71488272d5b7',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Op deze site kunt u zoeken op multimedia, specimens (collectie-exemplaren), taxa (dieren, planten, paddenstoelen), fossielen, mineralen en stenen.</p>

<p>De informatie komt uit de catalogi van <a href="http://www.naturalis.nl" style="text-decoration:none;" target="_blank">Naturalis Biodiversity Center</a> te Leiden, uit het <a href="http://www.nederlandsesoorten.nl/" style="text-decoration:none;" target="_blank">Nederlands Soortenregister</a> en uit de <a href="http://www.catalogueoflife.org/" style="text-decoration:none;" target="_blank">Catalogue of Life</a>.</p>

<p>Op de meeste specimenpagina’s is een PURL (Persistent Uniform Resource Locator) aanwezig. Als u een object wilt citeren dan kunt u gebruik maken van deze PURL. Naturalis stelt alles in het werk om het permanente karakter van deze PURL te garanderen.</p>

<p>Het BioPortal biedt vier mogelijkheden om deze gegevens te doorzoeken:</p>

<ul>
	<li><em><a href="#simple-search">Eenvoudig&nbsp;zoeken</a></em></li>
	<li><a name="simple-search"></a><em><a href="#advanced-search">Geavanceerd zoeken</a></em></li>
	<li><em><a href="#geo-search">Geografisch zoeken</a></em></li>
	<li><em><a href="#explore">Bijzondere collecties</a></em></li>
</ul>

<h2>Zoeken</h2>

<h3><br />Eenvoudig zoeken</h3>

<p>De zoekmachine in het BioPortal gebruikt uw zoektermen om de verschillende bronnen te doorzoeken. Hij kijkt daarbij naar alle relevante velden, zoals de populaire naam, wetenschappelijke naam, vindplaats en registratienummer. Simpel zoeken doorzoekt ook velden die niet worden doorzocht door geavanceerd zoeken.</p>

<p>Wanneer u een zoekopdracht uitvoert die uit meer dan één zoekterm bestaat, worden resultaten getoond waarin één, sommige of alle termen voorkomen. De resultaten worden zo weergegeven dat de best <em>matchende</em> bovenaan komt te staan.</p>

<p><a name="advanced-search"></a>Simpel zoeken herkent geen haakjes, aanhalingstekens of <em>wildcards</em> voor het beïnvloeden van de zoekactie. <a href="#advanced-search">Geavanceerd zoeken</a> biedt wel de mogelijkheid om meerdere woorden als één zoekterm in te voeren.</p>

<h3>Geavanceerd zoeken</h3>

<p>Door op het driehoekje in het gewone zoekveld te klikken, worden de geavanceerde zoekopties zichtbaar. Hiermee kan de zoekopdracht worden beperkt tot de categorieën multimedia, specimens en taxa, en specifieke velden binnen die categorieën.</p>

<p>Wanneer u voor meer categorieën zoektermen opgeeft, worden voor elke categorie resultaten getoond.</p>

<p>Om te bepalen hoe verschilende zoektermen worden gecombineerd in de zoekopdracht, kunt u onder “Combineer zoektermen” kiezen voor "Of" of "En". Kies "Of" om resultaten te tonen die één of meer van de ingevulde termen bevatten; kies "En" voor resultaten die ieder alle ingevulde termen bevatten.</p>

<p>Binnen de categorieën Specimens en Multimedia is het ook mogelijk te zoeken binnen een specifieke collectie door de naam van een collectie te kiezen in het veld Collectienaam. <a name="geo-search"></a>Eveneens kan de zoekopdracht&nbsp;voor de categorieën Specimens, Taxa en Multimedia beperkt worden tot een bronsysteem (b.v. Botany of Zoology and Geology catalogues).</p>

<h3>Geografisch zoeken</h3>

<p>Geografisch zoeken kan gebruikt worden om de zoekresultaten te beperken tot een bepaald gebied. Dit gebied kan gekozen worden uit de lijst gebieden rechts van de kaart of op de kaart getekend worden. Selecteer om zelf een gebied te tekenen het polygoon- of rechthoek-symbool midden bovenin de kaart, en klik vervolgens in de kaart om het gebied te tekenen.</p>

<p>Alleen resultaten waarvan de geografische coördinaten van de vindplaats opgenomen zijn in de bronsystemen worden hier getoond. De resultaten zijn daarom altijd beperkt tot specimens en multimedia.</p>

<p><a name="explore"></a>We maken gebruik van verschillende <a href="/colofon#databronnen?language=nl">bronnen</a>. Daardoor kan het voorkomen dat gebieden dubbel genoemd worden. Vaak verschillen deze gebieden in de gedetailleerdheid van de begrenzing.</p>

<h3>Bijzondere collecties</h3>

<p>Een eenvoudige en snelle manier van zoeken is “Bijzondere collecties”. Hiermee zie je alle specimens die behoren tot een van de bijzondere collecties van Naturalis. U krijgt direct alle resultaten te zien.</p>

<h2>Zoekresultaten</h2>

<p>Het&nbsp;BioPortal probeert snel de gewenste resultaten te leveren en gebruikt daarvoor <em>name resolution</em> en <em>ranking</em>.</p>

<h3>Name resolution</h3>

<p>Het BioPortal zal trachten een zoekterm te herleiden tot een wetenschappelijke naam. Dit wordt gedaan door verschillende velden te doorzoeken van het <a href="http://www.nederlandsesoorten.nl/" target="_blank">Nederlands Soortenregister</a> en de <a href="http://www.catalogueoflife.org/" target="_blank">Catalogue of Life</a>.</p>

<ol>
	<li>
	<p>Wetenschappelijke naam, zowel synoniemen als geaccepteerde wetenschappelijke namen</p>

	<ul>
		<li>
		<p>Bijvoorbeeld: <em>“Rattus norvegicus”</em></p>
		</li>
	</ul>
	</li>
	<li>
	<p>Een lijst met populaire namen in verschillende talen</p>

	<ul>
		<li>
		<p>Bijvoorbeeld “Bruine Rat” (Nederlands) of “Brown Rat ” (Engels)</p>
		</li>
	</ul>
	</li>
	<li>
	<p>Hogere ordeningen</p>

	<ul>
		<li>
		<p>Bijvoorbeeld “Rodentia” voor de biologische orde van de knaagdieren</p>
		</li>
	</ul>
	</li>
</ol>

<p><br />
De gevonden wetenschappelijke naam wordt vervolgens gebruikt voor het doorzoeken van multimedia en specimens. Hierdoor kan het zijn dat u de oorspronkelijke zoekopdracht niet letterlijk terugziet in de resultaten.</p>

<h3>Sortering</h3>

<p>De zoekresultaten worden geordend aan de hand van een interne manier van sorteren die vooral rekening houdt met hoe uniek de gevraagde zoektermen zijn binnen de index.&nbsp;</p>

<h3>Multimedia bij specimens</h3>

<p>Wanneer u via geavanceerd zoeken naar specimens gezocht, dan is er onder het totaaloverzicht van gevonden specimen een extra link beschikbaar, \'Toon alle <em>n</em> media objecten bij deze zoekopdracht\'. Via deze link kunt u direct alle mediaobjecten opvragen die gekoppeld zijn aan de specimen uit uw oorspronkelijke zoekopdracht. Opmerking: de geavanceerde zoekvelden voor specimen zijn uitgebreider dan die voor multimedia, waardoor u via deze functie indirect ook meer geavanceerde zoekopdrachten naar multimedia kunt uitvoeren.</p>

<h3>Weergave resultaten specimen</h3>

<p>In het scherm met resultaten uit de specimen-index heeft u de mogelijkheid om te schakelen tussen weergave als lijst van unieke specimens (\'Toon op specimen\'), en een weergave waarin de resultaten gegroepeerd zijn op soortsnaam (\'Toon op wetenschappelijke naam\'). Met die laatste weergave krijgt u snel inzicht in de verschillende soorten waarvoor er specimen gevonden zijn, terwijl de eerste weergave direct een compleet overzicht van de specimen geeft.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-10-21 12:37:22 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'API',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'en',
  'created' => 1493645561,
  'tnid' => 411615,
  'translate' => 0,
  'uuid' => '400c73b8-5ad3-44eb-a513-c019e8ef8fce',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>The Netherlands Biodiversity API is a biodiversity data service</h2>

<p>The Netherlands Biodiversity API is a modern data service for scientists, application developers, national and regional government bodies and anyone else interested in biodiversity and biodiversity-related data. This service starts with the&nbsp;biodiversity-related data of the <a href="http://www.naturalis.nl/en/" target="_blank">Naturalis Biodiversity Center</a>&nbsp;by granting access to its very extensive catalogue, historical and recent data relating to a variety of species, including specimen, multimedia and taxon data.</p>

<h2>Netherlands Biodiversity API offers a raft of possibilities</h2>

<p>The information released via this application is highly suitable for use by scientists working in taxonomical and thematic biodiversity studies. Detailed inventories of various types and a wide variety of (historical) data analyses are just some of the possible applications. For government bodies, the data can be an important source of information in developing new nature (conservation) policy as well as evaluating and monitoring existing policy in this field. Finally, application developers will be able to use the interface to bring plants, fungi, animals, fossils, minerals and rocks to life in interactive applications, aimed at specific target groups.</p>

<h2>Netherlands Biodiversity API starts by opening up the extensive Naturalis Collection</h2>

<p>The collection at Naturalis is one of the largest in the world and the quality of the objects is excellent.&nbsp;The collection represents an invaluable&nbsp;scientific value. Financed with FES (Economic Structure Enhancement) funds over the past few years, Naturalis has undertaken a unique digitisation project, according to which by 1 July 2015, all 42 million objects will have been recorded on digital cards, 8 million of them to a high level of detail. All in all, from the moment of its initial launch, this means that the Netherlands Biodiversity API is not only extensive in terms of size but also offers a valuable level of in-depth information.</p>

<h2>Netherlands Biodiversity API is freely accessible</h2>

<p>Unless stated otherwise, Naturalis has opted to place all its data in the public domain under&nbsp;<a href="https://creativecommons.org/choose/zero/?lang=en" target="_blank">CC0 licence</a>, making it free for all to use. Users do not require authorisation to gain access to the biodiversity data. This means that any form of reuse of the content of this site is permitted, except when for a piece of content (such as a photo or a document) copyright is indicated.</p>

<h2>Netherlands Biodiversity API and compatibility</h2>

<p>Naturalis aims to achieve compatibility with previous versions when carrying out maintenance on this API. Whenever it becomes necessary to add a function, as a consequence of which compatibility can no longer be guaranteed, the active version will continue to be maintained for a further six months, while the new function will only be available in the higher version. In the event of security problems or system abuse, Naturalis reserves the right to deviate from this principle.</p>

<h2>More about the Netherlands Biodiversity API</h2>

<p>Further information or questions about the Netherlands Biodiversity API:</p>

<p><a href="http://docs.biodiversitydata.nl" target="_blank">docs.biodiversitydata.nl</a>&nbsp;offers more functional and technical information.</p>

<p>For questions, requests or comments, please mail to <a href="mailto:nba@naturalis.nl">nba@naturalis.nl</a></p>

<p>&nbsp;</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-05-01 13:32:41 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Downloads',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'en',
  'created' => 1500543934,
  'tnid' => 3790,
  'translate' => 0,
  'uuid' => '40aaf623-f183-4bc3-a362-5dedaf994571',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>
Below are download links for Darwin Core Archives for the separate collections that make up the NBA.
</p>

<p>
Darwin Core Archive (DwC-A or DwCA) is a biodiversity informatics data standard that makes use of the Darwin Core terms to produce a single, self-contained dataset for species occurrence or checklist data. See TDWG\'s <a href="http://rs.tdwg.org/dwc/index.htm" target="_blank">Darwin Core introduction</a> for a more detailed description.
</p>

<p>
In this case, the files contain the specimen and multimedia data of the collection specified in it\'s name, with the exception of the \'nsr\' file, which contains names, taxonomy and occurrence status for all the species from the <a href="http://www.nederlandsesoorten.nl/" target="_blank">Dutch Species Register</a>.
</p>

<p>
The files listed below are generated weekly. The date part of the filename reflects the moment the file was generated, and does not hold any relation to the date the data was entered into the NBA, or the date the original data was created.
</p>

<p>Available data sets are:</p>

<?php 
echo getNbaData();
?>',
        'summary' => '',
        'format' => 'php_code',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Disclaimer',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'nl',
  'created' => 1418387013,
  'tnid' => 1,
  'translate' => 0,
  'uuid' => '4514bac5-0a1e-4989-ad4a-97a99e38a28c',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Aan het op bioportal.naturalis.nl juist weergeven van informatie is door de redactie van Naturalis Biodiversity Center uiterste zorg besteed.</h2>

<p>Naturalis Biodiversity Center aanvaardt echter geen enkele aansprakelijkheid voor schade als gevolg van het gebruik, op welke wijze dan ook, van de aangeboden informatie op deze internetsite.</p>

<h2>Rechten</h2>

<p>De redactie heeft alles in het werk gesteld om bij het gebruik van data, teksten en beelden op deze site geen belangen van derden te schenden. Een ieder die niettemin meent dat op deze site materiaal gebruikt is zonder dat daarover met hem of haar als mogelijke rechthebbende afspraken zijn gemaakt, verzoeken wij contact op te nemen met de redactie (<a href="mailto:bioportal@naturalis.nl">bioportal@naturalis.nl</a>).﻿</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-12-12 12:23:33 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'What\'s new',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'en',
  'created' => 1508844495,
  'tnid' => 3820,
  'translate' => 0,
  'uuid' => '46d4297a-a90c-4157-ab08-8209a20de589',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>v2.0:</p>

<ul>
	<li><u>New</u>: BioPortal uses the updated and much improved <a href="http://api.biodiversitydata.nl/v2">NBA v2.0</a> for data queries.</li>
	<li><u>New</u>: <a href="dashboard">Dashboard</a> demonstrating statistics of the Naturalis collection.</li>
	<li><u>New</u>: downloadable <a href="downloads">DarwinCore archives</a> of selected collections.</li>
	<li><u>New</u>: NBA queries are handled by a dedicated, open source <a href="https://github.com/naturalis/bioportal-php-client">PHP client</a> that mirrors the functionality of the <a href="https://github.com/naturalis/naturalis_data_api">NBA Java client</a>.</li>
	<li><u>New</u>: download images of specimens in the highest possible resolution.</li>
	<li><u>New</u>: provide feedback for inaccurate or erroneous specimen data.</li>
	<li><u>Improved</u>: specimen queries in the advanced search form have been merged into a single form.</li>
	<li><u>Improved</u>: clearer help texts for the advanced search form.</li>
	<li><u>Improved</u>: browse individual specimen, taxon and multimedia results (multimedia only in v1.0).</li>
	<li><u>Improved</u>: search results based on "name resolution" indicate the link between search term and result.</li>
	<li><u>Improved</u>: advanced search form has been tailored to the needs of collection administrators.</li>
	<li><u>Improved</u>: "show all media" links for specimen and taxon searches: fetch all media for your search criteria with a single click.</li>
	<li><u>Improved</u>: all nature areas in the <a href="geographic-search">geographical search form</a> now produce results.</li>
	<li><u>Fixed</u>: AND/OR queries now always produce accurate results.</li>
</ul>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-10-24 11:28:15 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Meteorieten collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1501151692,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '47fe504a-edce-43b5-8c96-2452112d3517',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Wij beheren bij Naturalis de grootste meteorieten collectie in Nederland, waaronder enkele unieke exemplaren. Deze diverse collectie omvat meteorieten die verzameld zijn over de hele wereld. In Nederland zijn 5 meteorieten teruggevonden na een inslag. In de collectie zitten 3 van deze meteorieten, de Uden meteoriet, de Glanerbrug meteoriet en de Diepenveen meteoriet. Naturalis is formeel erkend door de Meteoritical Society als meteoriet houdend instituut en er wordt veel onderzoek gedaan aan deze collectie. Analyses van meteorieten geven aanwijzingen over het ontstaan van het Zonnestelsel en het leven op Aarde. De gehele collectie is digitaal beschikbaar en aangevuld met foto’s van de meteorieten.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'meteorites',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-27 10:34:52 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Downloads',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'nl',
  'created' => 1501077177,
  'tnid' => 3790,
  'translate' => 0,
  'uuid' => '4b62ec6d-1a70-4ee6-8b10-7d0cba0e2bc9',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Hieronder vindt u downloadlinks naar Darwin Core Archive-bestanden voor de deelcollecties van de NBA.
</p>
<p>
Darwin Core Archive (DwC-A of DwCA) is een biodiversiteitsinformatica datastandaard die gebruik maakt van de Darwin Core termen om een enkele, op zichzelf staande dataset voor voorkomensgegevens of <em>checklist data</em> te produceren. Zie TDWG\'s <a href="http://rs.tdwg.org/dwc/index.htm" target="_blank">Darwin Core introductie (Engels)</a> voor een meer gedetailleerde beschrijving.
</p>

<p>
In dit geval bevatten de bestanden de specimen- en multimediagegevens van de collectie uit de betreffende bestandsnaam, met uitzondering van het \'nsr\'-bestand, dat namen, taxonomie en voorkeursstatus bevat voor alle soorten uit het <a href = "http : //www.nederlandsesoorten.nl/ "target =" _ blank ">Nederlands Soortenregister</a>.
</p>

<p>
Onderstaande bestanden worden wekelijks gegenereerd. De datum in de bestandsnaam correspondeert met het moment waarop het bestand gegenereerd is, en houdt geen verband met het moment van import in de NBA, dan wel de oorspronkelijke datum waarop de gegevens werden ingevoerd.
</p>

<p>De volgende datasets zijn beschikbaar:</p>

<?php 
echo getNbaData();
?>',
        'summary' => '',
        'format' => 'php_code',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-26 13:52:57 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'NBA Import',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'nl',
  'created' => 1508239048,
  'tnid' => 3818,
  'translate' => 0,
  'uuid' => '4d6f769f-d127-4c3b-9cb6-ae6ed215c753',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<table border="0" cellpadding="1" cellspacing="1">
	<tbody>
		<tr>
			<td><strong>Naturalis Botany catalogues</strong></td>
			<td style="text-align:right; white-space:nowrap">12 oktober 2017</td>
		</tr>
		<tr>
			<td><strong>Naturalis Zoology and Geology catalogues</strong></td>
			<td style="text-align:right; white-space:nowrap">14 oktober 2017</td>
		</tr>
		<tr>
			<td><strong>Naturalis bewaareenheden</strong></td>
			<td style="text-align:right; white-space:nowrap">22 mei 2017</td>
		</tr>
		<tr>
			<td><strong>Cataologue of Life</strong></td>
			<td style="text-align:right; white-space:nowrap">April 2017</td>
		</tr>
		<tr>
			<td><strong>Nederlands Soortenregister</strong></td>
			<td style="text-align:right; white-space:nowrap">14 oktober 2017</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-10-17 11:17:28 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'mineraal4',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'ndabio_header_image',
  'language' => 'en',
  'created' => 1416470934,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '626ffc19-1650-4885-8ccc-3f4ff9ea37a8',
  'field_ndabio_header_image' => array(),
  'date' => '2014-11-20 08:08:54 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'The Jongmans Collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500989226,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '701941e3-ca4e-4a88-8cc7-58b6ffec0ee5',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The Jongmans collection is the largest Dutch collection of Carboniferous fossils from the province of Limburg. The major part&nbsp;of the collection consists of beautifully preserved plant fossils. But faunal material is present as well. These mostly are aquatic animals, although some terrestrial animals - mainly insects - are also part of the collection.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'jongmans',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:27:06 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'De Mammoet-collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500988632,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '75fd8b66-6116-4b3b-9c2c-3be96caa3061',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Naturalis heeft een van de grootste collecties mammoetbotten ter wereld. De collectie omvat ca. 9000 specimens. Het merendeel hiervan is afkomstig uit de Noordzee. Bij het woord mammoet wordt meteen aan groot gedacht en natuurlijk bestaat de collectie grotendeels uit grote en zware objecten, maar ook kleine details zoals het eerste melkkiesje van een babymammoet en het fragiele tongbeen zijn in de collectie vertegenwoordigd. <a href="http://www.naturalis.nl/nl/kennis/collectie/Verhalen-uit-Naturalis/mammoet-collectie/"  target="_blank">Meer informatie</a></p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'mammoth',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:17:12 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'zilvermeeuw',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'ndabio_header_image',
  'language' => 'en',
  'created' => 1416470910,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '786b2489-998b-4794-87a6-bef7c2d87fb1',
  'field_ndabio_header_image' => array(),
  'date' => '2014-11-20 08:08:30 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Colophon',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'en',
  'created' => 1493645561,
  'tnid' => 3791,
  'translate' => 0,
  'uuid' => '794d5b17-da10-492e-839d-bbfce2ad70b4',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Terms of use</h2>

<p>Unless otherwise stated, for the content on this site the <a href="https://creativecommons.org/choose/zero/?lang=en" style="text-decoration:none;" target="_blank">CC0 licence</a> applies. This means that any form of reuse of the content of this site is permitted, except when for a piece of content (such as a photo or a document) copyright is indicated.</p>

<p>Naturalis signed the <a href="http://bouchoutdeclaration.org/" style="text-decoration:none;" target="_blank">Bouchout declaration</a> which aims to promote openness of biodiversity data and encourage digital access to those data.</p>

<h2>Website design and construction</h2>

<p>Naturalis Biodiversity Center</p>

<p><a name="datasources"></a></p>

<h2>Data sources</h2>

<ul>
	<li><a href="https://www.naturalis.nl/en/" style="text-decoration:none;" target="_blank">Naturalis Biodiversity Center</a>: botanical and zoological specimens,</li>
	<li><a href="http://www.nederlandsesoorten.nl/">Nederlands Soortenregister</a><a href="http://www.nederlandsesoorten.nl/" target="_blank">:</a> Dutch species information</li>
	<li><a href="http://www.catalogueoflife.org" style="text-decoration:none;" target="_blank">Species 2000 &amp; ITIS Catalogue of Life</a>: Annual Checklist 2015, global species information&nbsp;</li>
	<li><a href="http://www.natura2000.nl" style="text-decoration:none;" target="_blank">Natura 2000</a>: ESRI-files of nature reserves (Annemiek Adams)</li>
	<li><a href="http://www.staatsbosbeheer.nl/english" style="text-decoration:none;" target="_blank">Staatsbosbeheer</a>: ESRI-files of nature reserves (Jac Hakkens)</li>
	<li><a href="https://www.natuurmonumenten.nl" style="text-decoration:none;" target="_blank">Vereniging Natuurmonumenten</a>: ESRI-files of nature reserves (Rombout de Wijs)</li>
	<li><a href="http://www.pwn.nl" style="text-decoration:none;" target="_blank">PWN</a>: ESRI-files of nature reserves (Hubert Kivit)</li>
	<li><a href="http://www.landschapnoordholland.nl" style="text-decoration:none;" target="_blank">Landschap Noord-Holland</a>: ESRI-files of nature reserves (Ron van \'t Veer)</li>
	<li><a href="https://www.cbs.nl/en-gb" target="_blank">CBS Statistics Netherlands</a>: ESRI-bestanden of municipalities</li>
	<li><a href="http://gadm.org/" target="_blank">Global Administrative Areas</a>: ESRI-bestanden of administrative areas</li>
</ul>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-05-01 13:32:41 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Over',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'nl',
  'created' => 1493645348,
  'tnid' => 3796,
  'translate' => 0,
  'uuid' => '7b5e25e8-c9cb-49c0-b450-5d403222a1cc',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Het BioPortal is de nationale toegangspoort voor natuurhistorische informatie: van basisgegevens van museumobjecten tot en met volledige, geïllustreerde soortbeschrijvingen. Via één website ontsluit het BioPortal de gegevens van alle op objectniveau gedigitaliseerde collectieobjecten van Naturalis. Het BioPortal maakt daarbij gebruik van de Netherlands Biodiversity API (NBA). Nu zijn er al meer dan 8 miljoen Naturalis-objecten te doorzoeken, maar de informatie wordt continu verder uitgebreid en middels de NBA gekoppeld en ontsloten, waarmee we in Nederland over een website beschikken waarin digitale bronnen van gegarandeerde wetenschappelijk kwaliteit samen zijn te raadplegen.</p>

<p>Het BioPortal bevraagt via de NBA de volgende databronnen:</p>

<ul>
	<li>Brahms: botanische specimengegevens van Naturalis.</li>
	<li>Collectie Registratiesysteem (CRS): zoölogische, palaeontologische, mineralogische en petrologische specimengegevens van Naturalis.</li>
	<li><a href="http://www.nederlandsesoorten.nl" target="_blank">Nederlands Soortenregister</a>: lijst en beschrijvingen van alle in Nederland voorkomende soorten.</li>
	<li><a href="http://www.catalogueoflife.org/" target="_blank">Catalogue of Life</a>: lijst van wereldwijd voorkomende soorten.</li>
</ul>

<p>We noemen deze gegevensverzameling de NDS, de Naturalis Document Store. De gegevens worden via een ETL-proces in de NDS ingelezen en geharmoniseerd tot een ABCD-compatibel documentmodel.</p>

<p>Het BioPortal toont de kracht van de NBA. Het is een “klant” van de NBA, een voorbeeldapplicatie die de gegevens uit de NBA via een webportaal toegankelijk maakt. Via dit portaal kan iedereen, geïnteresseerde of wetenschapper, in de gegevensbronnen van Naturalis grasduinen, met simpele zoekopdrachten, via complexe queries of op basis van specifieke geografische locaties.</p>

<p>Ook een aantal bijzondere collecties van Naturalis wordt in het portaal uitgelicht, en zijn via het hoofdmenu direct te benaderen.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-05-01 13:29:08 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Colofon',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'nl',
  'created' => 1493645561,
  'tnid' => 3791,
  'translate' => 0,
  'uuid' => '7c8af603-88eb-418e-a735-6822dd7fe7f0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Gebruiksvoorwaarden</h2>

<p>Tenzij anders aangegeven is op de gegevens op deze site de <a href="http://creativecommons.nl/publiek-domein/" style="text-decoration:none;" target="_blank">CC0 verklaring</a> van toepassing. Dit betekent dat iedere vorm van (her)gebruik van de inhoud is toegestaan, met uitzondering van content (zoals fotomateriaal of documenten) waarvan auteursrecht expliciet wordt vermeld.</p>

<p>Naturalis heeft de <a href="http://bouchoutdeclaration.org/" style="text-decoration:none;" target="_blank">Bouchout Declaratie</a> ondertekend. Hiermee stimuleren en demonstreren we onze commitment aan vrij onderzoek. We streven er dan ook naar om digitale informatie over biodiversiteit publiek beschikbaar te maken via kanalen zoals dit portaal.</p>

<h2>Ontwerp en technische realisatie</h2>

<p>Naturalis Biodiversity Center</p>

<p><a name="databronnen"></a></p>

<h2>Databronnen</h2>

<ul>
	<li><a href="https://www.naturalis.nl/nl/" style="text-decoration:none;" target="_blank">Naturalis Biodiversity Center</a>: botanische en zoölogische specimens</li>
	<li><a href="http://www.nederlandsesoorten.nl/" target="_blank">Nederlands Soortenregister:</a> soortinformatie Nederlandse soorten</li>
	<li><a href="http://www.catalogueoflife.org" style="text-decoration:none;" target="_blank">Species 2000 &amp; ITIS Catalogue of Life</a>: Annual Checklist 2016, soortinformatie wereldwijd</li>
	<li><a href="http://www.natura2000.nl" style="text-decoration:none;" target="_blank">Natura 2000</a>: ESRI-bestanden van natuurgebieden (Annemiek Adams)</li>
	<li><a href="http://www.staatsbosbeheer.nl" style="text-decoration:none;" target="_blank">Staatsbosbeheer</a>: ESRI-bestanden van natuurgebieden (Jac Hakkens)</li>
	<li><a href="https://www.natuurmonumenten.nl" style="text-decoration:none;" target="_blank">Vereniging Natuurmonumenten</a>: ESRI-bestanden van natuurgebieden (Rombout de Wijs)</li>
	<li><a href="http://www.pwn.nl" style="text-decoration:none;" target="_blank">PWN</a>: ESRI-bestanden van natuurgebieden (Hubert Kivit)</li>
	<li><a href="http://www.landschapnoordholland.nl" style="text-decoration:none;" target="_blank">Landschap Noord-Holland</a>: ESRI-bestanden van natuurgebieden (Ron van \'t Veer)</li>
	<li><a href="https://www.cbs.nl/nl-nl" target="_blank">Centraal Bureau voor de Statistiek</a>: ESRI-bestanden van gemeenten</li>
	<li><a href="http://gadm.org/" target="_blank">Global Administrative Areas</a>: ESRI-bestanden van administratieve gebieden</li>
</ul>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-05-01 13:32:41 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'De Jongmans-collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500989081,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '8a0dbf70-5be2-4e08-9b87-527298592088',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>De Jongmans-collectie is de grootste Nederlandse collectie van Carboonmateriaal uit Limburg. Het overgrote deel bestaat uit prachtig bewaarde plantenfossielen. Maar ook faunamateriaal is bewaard gebleven. Het gaat dan met name om fossielen van dieren die in zoet- en zoutwateromstandigheden leefden, hoewel er ook een aantal landdieren - en dan voornamelijk insecten - aanwezig zijn.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'jongmans',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:24:41 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Prentencollectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500543934,
  'tnid' => 3406,
  'translate' => 0,
  'uuid' => '8e9b0428-45a4-46ce-8bd7-e2201c73d0bc',
  'body' => array(),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'arts',
        'format' => NULL,
      ),
    ),
  ),
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Martin Collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1501152048,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '93440688-f303-447a-83dc-e6f0898df8a8',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Naturalis houses the probably largest collection in the world of cainozoic molluscs from Indonesia. The most important part of it is the so-called Martin Collection of fossil shells from Java. The materials were collected between 1845 and 1910 by a.o. Franz Junghuhn, Pieter van Dijk, Rogier Verbeek, Karl Martin and his wife Hillegonda Martin-Icke. Thanks to the extensive taxonomical studies of Martin and his wife the Martin Collection has become a frequently consulted key collection for South-East Asian molluscs, fossil and recent. It contains nearly 2000 type lots of hundreds of species. Data on all samples and photographs of all types can be consulted via the Bioportal. Also available online are two versions of the type catalogue: (<a href="http://www.repository.naturalis.nl/document/45042" target="_blank">version 2002</a>) and (<a href="http://www.repository.naturalis.nl/document/143887" target="_blank">version 2009</a>).</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'martin',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-27 10:40:48 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Beekbergerwoud Collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500543934,
  'tnid' => 3408,
  'translate' => 0,
  'uuid' => '944d927e-dca4-4567-8d40-0f2e13b2a0c9',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Het Beekbergerwoud behoort met 160 vermelde en/of verzamelde plantensoorten uit de periode 1827-1875 tot de best doorvorste Nederlanse natuurgebieden uit de 19de eeuw. Wat nog niet volledig geïnventariseerd is zijn de zoölogische collecties uit het Beekbergerwoud gemaakt in dezelfde periode. Dat is een gemis omdat herintroductie van lokaal uitgestorven soorten zich tegenwoordig allang niet meer beperkt tot alleen plantensoorten. Het bijeenbrengen van deze gegevens zal toekomstige herintroducties van de vroegere fauna uit het Beekbergerwoud helpen faciliteren zodat herstel van de dierenwereld van dit bos geen eeuwen hoeft te duren.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'beekbergerwoud',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Contact',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_service_menu_page',
  'language' => 'en',
  'created' => 1413984173,
  'tnid' => 6,
  'translate' => 0,
  'uuid' => 'a2f56bf1-1289-45f2-96a5-c25a057d6679',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Questions and feedback for BioPortal website</h2>

<table border="0" style="width:100%">
	<tbody>
		<tr>
			<td style="width:50%">E-mail</td>
			<td><a href="mailto:bioportal@naturalis.nl">bioportal@naturalis.nl</a></td>
		</tr>
	</tbody>
</table>

<h2>Questions and feedback for BioPortal content</h2>

<table border="0" style="width:100%">
	<tbody>
		<tr>
			<td style="width:50%">E-mail<br />
			If applicable add source and collection name to the subject.</td>
			<td style="vertical-align:top"><a href="mailto:collectie@naturalis.nl?subject=Bioportal content: [source] [collection name]">collectie@naturalis.nl</a></td>
		</tr>
	</tbody>
</table>

<h2>Naturalis Biodiversity Center</h2>

<table border="0" style="width:100%">
	<tbody>
		<tr>
			<td style="width:50%">Museum address</td>
			<td>Pesthuislaan 7,&nbsp;2333 BA&nbsp; Leiden</td>
		</tr>
		<tr>
			<td style="width:50%">Visiting address (general)</td>
			<td>Vondellaan 55, 2332 AA&nbsp; Leiden</td>
		</tr>
		<tr>
			<td style="width:50%">Visiting address (herbarium)</td>
			<td>Nieuwenhuizenweg 19, 2314 XP&nbsp; Leiden</td>
		</tr>
		<tr>
			<td>Postal address</td>
			<td>Postbus 9517, 2300 RA&nbsp; Leiden</td>
		</tr>
		<tr>
			<td>Telephone number</td>
			<td>+31-(0)71-7519600</td>
		</tr>
		<tr>
			<td>E-mail</td>
			<td><a href="mailto:contact@naturalis.nl">contact@naturalis.nl</a></td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-10-22 13:22:53 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'De Dubois-collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500988459,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'a8aa2a2f-a8f9-4041-8f86-13ec6d43c45b',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>De Dubois-collectie bestaat uit zo’n 40.000 objecten die tussen 1887 en 1900 door Eugène Dubois verzameld zijn in Indonesië. Het is een unieke verzameling fossielen die een beeld geeft van de prehistorische fauna op Java en Sumatra, maar ook van de persoon Dubois en zijn toewijding aan het paleontologisch onderzoek. Naast fossielen bevat de collectie persoonlijke eigendommen, zoals een archief, meetinstrumenten, het koffertje van Dubois en zelfs enkele van zijn tanden die getrokken moesten worden en die hij gebruikte om ze te vergelijken met fossiele tanden van mensen en apen. De collectie is meer dan een verzameling oude fossielen in een opslagruimte, ze vertelt het verhaal van een bijzondere man die grote dromen had en er alles voor over had om zijn doelen te bereiken. De vondsten van Dubois spelen een belangrijke rol in de kennis die we hebben over de evolutie van de mens. Het was Dubois’ levensdoel om de evolutietheorie van Darwin te bewijzen, door op zoek te gaan naar de ‘Missing Link’, de ontbrekende schakel tussen aap en mens. Dubois slaagde in zijn missie maar kreeg niet de erkenning waar hij op hoopte. In de laatste decennia is dit veranderd en de Dubois-collectie wordt heden ten dage door onderzoekers van over de gehele wereld onderzocht. <a href="http://www.naturalis.nl/nl/kennis/collectie/Verhalen-uit-Naturalis/Duboiscollectie/" target="_blank">Meer informatie</a></p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'dubois',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:14:19 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Beekbergerwoud Collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500543934,
  'tnid' => 3408,
  'translate' => 0,
  'uuid' => 'aa7323fe-cb8d-469b-99e3-99fb10de4a0a',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>With 160 registered and/or collected plant species from the period 1827-1875, the Beekbergerwoud is one of the most closely scrutinised 19th century Dutch nature conservation areas. However, the zoological collections from the Beekbergerwoud assembled during the same period have not yet been fully inventorised. This is a clear lacuna, as the reintroduction of locally-extinct species is nog longer restricted to plant species alone for some time already.&nbsp;<br />
Bringing all information together will help distinguish facts from fables in the myths that have arisen around the Beekbergerwoud, enabling the recovery of the original biodiversity.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'beekbergerwoud',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Extinct Birds',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500543934,
  'tnid' => 3410,
  'translate' => 0,
  'uuid' => 'ae3e44ac-969a-46ab-839e-a09f9cb81792',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The more than 200 extinct birds in the Naturalis collection are a collection highlight which raises much interest among ornithologists. 135 extinct bird&nbsp;specimens are accessible through the BioPortal. Some of these specimens are unique. Naturalis is the only museum in the world to hold a Tahiti-Sandpiper <em>Prosobonia leucoptera</em> (Gmelin, 1789) and a specimen of Sharpe\'s Rail <em>Gallirallus sharpei</em> (Büttikofer, 1893). You can view the digitized extinct birds from all angles by rotating the 3d-images.</p>

<p>The nomenclature is based on The Howard &amp; Moore Complete Checklist of the Birds of the World Dickinson, E.C. (Editor) 3rd Edition, Princeton University Press, 2003.</p>

<div>&nbsp;</div>

<div>&nbsp;</div>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'extinct-birds',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'paddestoelen',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'type' => 'ndabio_header_image',
  'language' => 'en',
  'created' => 1416470954,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'b517cdec-8a56-49ee-92eb-cb56e536dd4d',
  'field_ndabio_header_image' => array(),
  'date' => '2014-11-20 08:09:14 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Meteorite collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1501151651,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'b686fa34-360a-4f3d-80b7-2aa8f58e0155',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>At Naturalis we preserve the largest meteorite collection in the Netherlands, including some unique specimens. The&nbsp;diverse collection includes meteorites collected around the world. In the Netherlands 5 meteorites have been recovered after an impact. Our collection includes 3 of these meteorites, the Uden meteorite, the Glanerbrug meteorite and the Diepenveen meteorite. Naturalis has been formally acknowledged by the Meteoritical Society as a meteorite institute and much research is being done on this collection. Analyses of meteorites provide evidence of the origin of the Solar System and life on Earth. The entire collection is digitally available and supplemented with photographs of the meteorites.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'meteorites',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-27 10:34:11 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Wat is er nieuw',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'nl',
  'created' => 1508844448,
  'tnid' => 3820,
  'translate' => 0,
  'uuid' => 'c198f239-f0ed-4a21-8822-32dd38df828f',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>v2.0:</p>

<ul>
	<li><u>Nieuw</u>: BioPortal gebruikt de vernieuwde en sterk verbeterde <a href="http://api.biodiversitydata.nl/v2">NBA v2.0</a> voor zoekopdrachten.</li>
	<li><u>Nieuw</u>: <a href="dashboard">Dashboard</a> met statistieken over de Naturalis collectie.</li>
	<li><u>Nieuw</u>: downloadbare <a href="downloads">DarwinCore archives</a> van een deel van de collectie.</li>
	<li><u>Nieuw</u>: NBA zoekopdrachten worden uitgevoerd met een speciaal daarvoor geschreven open source <a href="https://github.com/naturalis/bioportal-php-client">PHP client</a> met dezelfde functionaliteit als de <a href="https://github.com/naturalis/naturalis_data_api">NBA Java client</a>.</li>
	<li><u>Nieuw</u>: download afbeeldingen van specimens in de hoogste resolutie.</li>
	<li><u>Nieuw</u>: optie om onvolkomenheden of fouten te rapporteren bij specimens.</li>
	<li><u>Verbeterd</u>: zoekopdrachten voor specimens in uitgebreid zoeken samengevoegd tot één formulier.</li>
	<li><u>Verbeterd</u>: duidelijkere helpteksten bij uitgebreid zoeken.</li>
	<li><u>Verbeterd</u>: blader door de individuele specimen-, taxon- en multimediaresultaten (alleen multimedia in v1.0).</li>
	<li><u>Verbeterd</u>: resultaten gebaseerd op "name resolution" tonen het verband tussen zoekterm en resultaat.</li>
	<li><u>Verbeterd</u>: uitgebreid zoekformulier aangepast naar de wensen van collectiebeheerders.</li>
	<li><u>Verbeterd</u>: "toon alle media" links voor specimen en taxon zoekopdrachten: haal met één klik alle media op voor uw zoekcriteria.</li>
	<li><u>Verbeterd</u>: alle natuurgebieden in het <a href="geographic-search">geografisch zoekformulier</a> tonen nu resultaten.</li>
	<li><u>Opgelost</u>: EN/OF zoekopdrachten produceren nu altijd betrouwbare resultaten.</li>
</ul>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-10-24 11:27:28 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'De Siebold Collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500543934,
  'tnid' => 3409,
  'translate' => 0,
  'uuid' => 'c1b250fb-f79b-403b-93a9-61bf7d7d7b34',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>De Siebold Collectie van natuurhistorische objecten omvat in totaal 200 zoogdieren, 900 vogels, 750 vissen, 170 reptielen, meer dan 5000 ongewervelde dieren, 2000 verschillende soorten planten en 12.000 herbariumexemplaren. Een groot deel hiervan bevindt zich in de opslagtoren van Naturalis, een deel hiervan is ook gedigitaliseerd en beschikbaar in het BioPortal. Von Siebold verzamelde het materiaal tussen 1823 en 1829 tijdens zijn verblijf in Japan. De collectie was de eerste grote verzameling van Japanse specimen in Europa en bevatte veel tot dan toe onbekende dier- en plantensoorten.&nbsp;<a href="https://www.naturalis.nl/nl/kennis/collectie/Verhalen-uit-Naturalis/siebold-de-collectie/" style="line-height: 20.7999992370605px; text-decoration: none;" target="_blank">Lees meer</a></p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'siebold',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'De Timor collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500988915,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'd5a22f32-ab66-47c1-b9a4-57bc468d9400',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>In het Perm en Trias lag er in het gebied dat nu het Indonesische eiland Timor heet een ondiepe zee met daarin een heel soortenrijk rif. De fossielen die dat rif vertegenwoordigen zijn uitzonderlijk goed bewaard gebleven en vormen een unieke bron van informatie voor het reconstrueren van de mariene wereld in het Perm en Trias.</p>

<p>Tussen 1910 en 1916 werden verschillende expedities vanuit de Technische Hoogeschool Delft (nu TU Delft) naar het Indonesische eiland Timor ondernomen. In 1937 werd er nogmaals een expeditie ondernomen - dit keer vanuit het Geologisch Instituut van de Universiteit van Amsterdam. In Naturalis zijn de twee collecties samengevoegd, volledig geregistreerd en toegankelijk gemaakt voor onderzoek.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'timor',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:21:55 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Uitgestorven Vogels',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1500543934,
  'tnid' => 3410,
  'translate' => 0,
  'uuid' => 'dc75ec2d-53f8-4e64-809d-feb302cf1193',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>De meer dan 200 uitgestorven vogelsoorten in de Naturalis collectie zijn een collectiehoogtepunt waar veel interesse voor is vanuit ornithologen. 135 van deze soorten zijn beschikbaar in het BioPortal. Sommige exemplaren zijn uniek. Zo is Naturalis het enige museum in de wereld dat een Tahitistrandloper <em>Prosobonia leucoptera</em> (Gmelin, 1789) en een exemplaar van de Büttikofer-ral <em>Gallirallus sharpei</em> (Büttikofer, 1893) in de collectie heeft. Je kan hier de gedigitaliseerde uitgestorven vogels van alle kanten bekijken middels draaiende 3d-beelden.</p>

<p>De nomenclatuur is gebaseerd op The Howard &amp; Moore Complete Checklist of the Birds of the World Dickinson, E.C. (Editor) 3rd Edition, Princeton University Press, 2003.</p>

<div>&nbsp;</div>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'extinct-birds',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-20 09:45:34 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'The Dubois collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500988549,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'e3b52db4-a18d-4073-9a9c-8c05614d283e',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The Dubois collection consists of circa 40,000 objects, all collected between 1887 and 1900 in Indonesia by Eugène Dubois. It is a unique collection of fossils, providing an overview of the prehistoric fauna on Java and Sumatra, but as well of Dubois as a person and his dedication to palaeontological research. Besides fossils, the collections holds&nbsp;a vast archive and some of Dubois’ personal belongings, such as measuring instruments, his suitcase and some of his own teeth which he used to compare with fossil teeth of primates. The collection is much more than just a collection of fossils in a storage space, it tells the story of a remarkable man, his dreams and his determination to reach his goals. Dubois’ findings play a very important role in the knowledge we have today on human evolution. It was Dubois’ life goal to prove Darwin’s theory of evolution by searching for the Missing Link between apes and humans. Dubois succeeded but unfortunately did not get the recognition he hoped for. In recent decades this has changed and the Dubois collection is subject to research by scholars worldwide. <a href="http://www.naturalis.nl/nl/kennis/collectie/Verhalen-uit-Naturalis/Duboiscollectie/" target="_blank">More information</a> [Dutch]</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'dubois',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:15:49 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'The Timor collection',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'en',
  'created' => 1500988964,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'e7c4056c-863f-49dc-bf70-1480e1f2b3b5',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>During the Permian and Triassic the area which is now the Indonesian island of Timor was covered with a shallow sea containing a very species diverse reef. The fossils representing that reef are remarkably well preserved en form a unique source of information for the reconstruction of the Permian and Triassic marine world.</p>

<p>Between 1910 and 1916 a number of expeditions were undertaken by the Technische Hoogschool Delft (now Delft University of Technology) to the Indonesian island of Timor. In 1937 the Geological Institute of the University of Amsterdam continued the fieldwork. In Naturalis both collections have been merged, digitized and made available for research.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'timor',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-25 13:22:44 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'API',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_page',
  'language' => 'nl',
  'created' => 1493645348,
  'tnid' => 411615,
  'translate' => 0,
  'uuid' => 'e96f0452-3460-4202-964f-9451ae5a7aa9',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>Netherlands Biodiversity API is een biodiversiteitsdataservice</h2>

<p>De Netherlands Biodiversity API is een moderne dataservice voor wetenschappers, applicatieontwikkelaars, nationale en regionale overheidsinstanties, en andere geïnteresseerden in biodiversiteit en biodiversiteitsgegevens. Deze dienst start met het beschikbaar stellen van biodiversiteitsgegevens van <a href="http://www.naturalis.nl" target="_blank">Naturalis Biodiversity Center</a>. &nbsp;Door haar zeer omvangrijke catalogi open te stellen komen diverse soorten historische en actuele data beschikbaar, zoals specimen-, multimedia- en taxongegevens.</p>

<h2>Netherlands Biodiversity API biedt mogelijkheden</h2>

<p>De vrijgegeven gegevens zijn uitstekend geschikt voor gebruik door wetenschappers, werkzaam in het taxonomisch en thematisch biodiversiteitsonderzoek. Gedetailleerde inventarisaties van verschillende aard en een brede variëteit aan (historische) data-analyses behoren tot de gebruiksmogelijkheden. Voor overheden kunnen de gegevens een belangrijke bron van informatie vormen bij het ontwikkelen van nieuw natuur(bescherming)beleid, en het evalueren en monitoren van staand beleid op dit terrein. Applicatieontwikkelaars tenslotte, kunnen voor specifieke doelgroepen planten, paddenstoelen, dieren, fossielen, mineralen en gesteenten tot leven laten komen in interactieve applicaties.</p>

<h2>Netherlands Biodiversity API begint met het ontsluiten van de omvangrijke Naturalis Collectie</h2>

<p>De collectie van Naturalis behoort tot de grootste van de wereld. Het grote aantal objecten&nbsp;is van hoge kwaliteit en vertegenwoordigt&nbsp;een onschatbare wetenschappelijke waarde. Met financiering vanuit de FES-gelden (Fonds Economische Structuurversterking) heeft Naturalis de afgelopen jaren een uniek digitaliseringsproject uitgevoerd, waarmee alle 42 miljoen objecten op 1 juli 2015 digitaal in kaart zijn gebracht, waarvan 8 miljoen objecten op een hoog detailniveau. Dit alles maakt dat de Netherlands Biodiversity API een omvangrijke gegevensverzameling met een grote mate van diepgang toegankelijk maakt.</p>

<h2>Netherlands Biodiversity API is vrij toegankelijk</h2>

<p>Tenzij anders aangegeven zet Naturalis al haar data in het open domein onder&nbsp;<a href="http://creativecommons.nl/publiek-domein/" target="_blank">CC0-licentie</a>, dus vrij voor een ieder om te gebruiken. Een gebruiker heeft geen autorisatie nodig om toegang te krijgen tot de biodiversiteitsgegevens.&nbsp;Dit betekent dat iedere vorm van (her)gebruik van de inhoud is toegestaan, met uitzondering van content (zoals fotomateriaal of documenten) waarvan auteursrecht expliciet wordt vermeld.</p>

<h2>Netherlands Biodiversity API en compatibiliteit</h2>

<p>Naturalis streeft naar compatibiliteit bij het onderhoud van deze API met eerdere versies. Wanneer het noodzakelijk is om functionaliteit toe te voegen waardoor deze compatibiliteit niet meer kan worden gegarandeerd, dan zal de actieve versie nog zes maanden onderhouden worden, en zal de nieuwe functionaliteit alleen in de hogere versie beschikbaar zijn. In het geval van veiligheidsproblemen of onjuist gebruik behoudt Naturalis zich het recht voor om hiervan af te wijken.</p>

<h2>Meer over Netherlands Biodiversity API</h2>

<p>Informatie of vragen over de Netherlands Biodiversity API:</p>

<p>Op <a href="http://docs.biodiversitydata.nl/en/latest/" target="_blank">docs.biodiversitydata.nl</a> vindt u meer functionele en technische informatie over de API.</p>

<p>Voor vragen, verzoeken en opmerkingen kunt u mailen met <a href="mailto:nba@naturalis.nl">nba@naturalis.nl</a></p>

<p>&nbsp;</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_file' => array(),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-05-01 13:29:08 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Martin Collectie',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_featured_content',
  'language' => 'nl',
  'created' => 1501151975,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'f0783412-967d-4c0f-96e9-b0e05567cab6',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Naturalis beheert de waarschijnlijk grootste collectie ter wereld van cainozoïsche mollusken uit Indonesië. Het belangrijkste onderdeel hiervan is de zogenaamde Martin Collectie met fossiele schelpen van Java. Dit materiaal werd tussen 1845 en 1910 verzameld door o.a. Franz Junghuhn, Pieter van Dijk, Rogier Verbeek, Karl Martin en zijn vrouw Hillegonda Martin-Icke. Dankzij de uitgebreide taxonomische studies door Martin en zijn vrouw is de Martin Collectie een veel geraadpleegde sleutelcollectie geworden voor Zuidoost-Aziatische mollusken, fossiel en recent. Zij bevat bijna 2000 typenmonsters van vele honderden soorten. Gegevens van de monsters en foto’s van alle typen zijn via het Bioportal te raadplegen. Ook zijn twee versies van de typencatalogus online beschikbaar: (<a href="http://www.repository.naturalis.nl/document/45042" target="_blank">versie 2002</a>) en (<a href="http://www.repository.naturalis.nl/document/143887" target="_blank">versie 2009</a>).</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'field_nba_search_term' => array(
    'und' => array(
      0 => array(
        'value' => 'martin',
        'format' => NULL,
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 1,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2017-07-27 10:39:35 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  $nodes[] = array(
  'title' => 'Help',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'naturalis_help',
  'language' => 'en',
  'created' => 1418640288,
  'tnid' => 2,
  'translate' => 0,
  'uuid' => 'f5db4539-d3d6-4008-8725-ad5156f4be66',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>On this site, you can search for multimedia, specimens (collection specimens) and taxa (species descriptions of animals, plants, fungi), fossils, minerals and rocks.</p>

<p>The information will be supplied from the catalogues of <a href="https://www.naturalis.nl/en/" style="text-decoration:none;" target="_blank">Naturalis Biodiversity Center</a> in Leiden, from the <a href="http://www.nederlandsesoorten.nl/content/english" style="text-decoration:none;" target="_blank">Nederlands Soortenregister</a> and the <a href="http://www.catalogueoflife.org/" style="text-decoration:none;" target="_blank">Catalogue of Life</a>.</p>

<p>On practically every specimen-page a PURL (Persistent Uniform Resource Locator) is present. You can cite the object described here by using this PURL. Naturalis will try to assure the permanent character of this PURL.</p>

<p>The BioPortal offers four possibilities for browsing this data:</p>

<ul>
	<li><a href="#simple-search"><em>Simple search</em></a></li>
	<li><a href="#advanced-search"><em>Advanced search</em></a></li>
	<li><em><a href="#geo-search">Geographic search</a></em></li>
	<li><a name="simple-search"></a><em><a href="#explore">Explore highlights</a></em></li>
</ul>

<h2><strong>Searching</strong></h2>

<h3><br />
<strong>Simple Search</strong></h3>

<p>Bioportal works in the same way as other well-known search engines: it uses your search terms to browse our sources. Within its search operations, it will examine all the fields specified in the advanced search (such as popular name, scientific name or discovery location) and will even browse fields not accessible via the advanced search.</p>

<p>If you type more than one search term, we will display all the results in which one, some or all of the terms occur, but we will head the list with results with the best match.</p>

<p>When you make a simple search the search term will be analyzed and if there are more terms the search is divided into various parts. All these parts lead to potential search results and are combined with an OR, which can lead to very big search result sets.</p>

<p><a name="advanced-search"></a>It is not possible to use brackets, double-quotes or so-called wildcards to constrict or widen your searchterms. All foreign characters will be ignored in the query. To combine search terms, use the <a href="#advanced-search">Advanced Search</a> option.</p>

<h3><strong>Advanced Search</strong></h3>

<p>By clicking on the triangle symbol in the entry field, you will leave the <em>simple search </em>application, and start an <em>advanced search</em>. This means that you will limit your results to the category in which you are searching (multimedia, specimen or taxon) and to the specific fields in which you are searching.</p>

<p>If you enter search terms for more than one category, the result for each category will be shown.</p>

<p>When entering multiple search&nbsp;terms in the same category, you can use the&nbsp;‘Combine search terms’ switch to influence the behaviour of the search engine. Choose \'Or\'&nbsp;for results that include one or more of these terms, or&nbsp;‘And’ for results that contain all terms.</p>

<p>Within the categories specimens and multimedia, you also have the option to restrict your search to a specific collection by selecting its name in the Collection name field. <a name="geo-search"></a>You can also limit your query for the categories Collection specimens, Taxa and Multimedia by selecting a specific Source (e.g. Botany or Zoology and Geology catalogues).</p>

<h3><strong>Geographic Search</strong></h3>

<p>You can use a geographic search to rapidly limit the number of search results to a particular area. The area can be selected from a list of areas on the right-hand side of the map, or drawn onto the map.</p>

<p>The results will always be limited to collection specimens and multimedia. Within this search type, only those results for which the geographical coordinates of the discovery location are stored in the source systems will be displayed.</p>

<p><a name="explore"></a>We make use of a range of different <a href="/colophon#datasources?language=en">sources</a>. This means that in some cases, areas may be listed more than once. These areas will often differ in terms of degree of detail of the boundaries.</p>

<h3><strong>Explore Highlights</strong></h3>

<p>A simple and rapid search method is ‘Explore Highlights’. This search will result in a reproduction of all specimens that belong to one of the Special Collections at Naturalis. The results will be displayed immediately.</p>

<h2><strong>Search results</strong></h2>

<p>The aim of BioPortal is to deliver the results you are looking for quickly, and with that in mind, the system will use <em>name resolution</em> and <em>ranking</em>.</p>

<h3><strong>Name resolution</strong></h3>

<p>The BioPortal will attempt to convert your search term to a scientific name. This will be achieved by searching through various fields in the <a href="http://www.nederlandsesoorten.nl/content/english" target="_blank">Nederlands Soortenregister</a> and the <a href="http://www.catalogueoflife.org/" target="_blank">Catalogue of Life</a>.</p>

<p>1. &nbsp;&nbsp;&nbsp;Scientific name<br />
○ &nbsp;&nbsp;&nbsp;&nbsp;For example: <em>“Rattus norvegicus”</em><br />
2. &nbsp;&nbsp;&nbsp;A list of popular names in various languages<br />
○ &nbsp;&nbsp;&nbsp;&nbsp;One example is ‘Bruine Rat’ (Dutch) or “Brown Rat ” (English)<br />
3. &nbsp;&nbsp;&nbsp;Higher orders<br />
○ &nbsp;&nbsp;&nbsp;&nbsp;For example “Rodentia” for the biological order rodents</p>

<p>This scientific name is then used to browse through multimedia and specimens. This may mean that your original query will not necessarily be literally reproduced in the results.</p>

<h3><strong>Ranking</strong></h3>

<p>Search results are sorted using an internal algorithm that primarily takes into account the level of uniqueness of the search terms within the entire index.</p>

<h3><strong>Multimedia for specimens</strong></h3>

<p>When you search&nbsp;for specimen through the advanced search form, there will appear an additional link underneath the search results, \'Show all <em>n</em>&nbsp;media items for this query\'. Using this link, you can access all multimedia objects associated with the specimens in the resultset of your original search action. Please note: the advanced search form for specimen allows for searching a broader set of fields than that for multimedia. However, the function described above allows you to indirectly execute more advanced&nbsp;multimedia searches.</p>

<h3><strong>Displaying specimen results</strong></h3>

<p>In the screen displaying search results from the specimen index you can switch between two display modes: \'Display by specimen\', which lists the results as one long list, giving you an overview of all found specimen. Alternatively, you can choose \'Display by scientific name\', which&nbsp;lists the&nbsp;results grouped by scientific name, which allows you to quicky assess the different species for which specimens have been found.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'path' => array(
    'pathauto' => 0,
  ),
  'pathauto_perform_alias' => FALSE,
  'date' => '2014-12-15 10:44:48 +0000',
  'user_uuid' => '3f7b751f-de9b-4b15-b939-437e11ff7ae7',
);
  return $nodes;
}
