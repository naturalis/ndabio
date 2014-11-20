<?php
/**
 * @file
 * bioportal_serrvice_menu_pages.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function bioportal_serrvice_menu_pages_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'title' => 'Disclaimer',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'ds_switch' => '',
  'type' => 'naturalis_service_menu_page',
  'language' => 'und',
  'created' => 1413896301,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '1dfa43fc-f62c-4d40-a016-4e4f40952954',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Every effort has been taken to ensure the accuracy of the information on biportal.naturalis.nl.</p>

<p>However, Naturalis Biodiversity Center excludes all and any liability for damage resulting from the use, in whatever manner, of information supplied on this site.</p>

<h2>Intellectual Property Rights</h2>

<p>Every effort has been taken to protect the interests of third parties when using data, texts and pictures. If, however, you believe that this site contains material that is subject to intellectual property rights without agreements having been made with the rightful owner, please contact the web editors.</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-21 12:58:21 +0000',
  'user_uuid' => 'd4fc88d0-c5d0-4ad1-a390-c5ee98f38dd5',
);
  $nodes[] = array(
  'title' => 'Help',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'ds_switch' => '',
  'type' => 'naturalis_help',
  'language' => 'und',
  'created' => 1413895042,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '3fbad984-3780-4e5e-b2a9-71488272d5b7',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>BioPortal is designed to give you quickly the result that you’re most likely looking for. It does so by using two mechanisms: <strong><em>Name Resolution</em></strong> and <strong><em>Relevance Soring</em></strong></p>

<p>If you need more fine-grained control over the search results, you can use <strong><em>advanced search</em></strong>, by clicking on the arrow in the search field.</p>

<h2>Name Resolution</h2>

<p>BioPortal will try to match your search term with one or more <em>accepted scientific name(s)</em></p>

<p>The matching of your search term to <em>accepted scientific names</em> is done by searching through various fields of our databases:</p>

<ol>
	<li><strong>qualified scientific species name</strong>.

	<ul>
		<li>An example of such a name is: “<em>Panthera leo</em>”</li>
	</ul>
	</li>
	<li>a list of <strong>common names</strong> or <em>Vernacular names</em>
	<ul>
		<li>An example of such a name is “Lion” (English) or "Leeuw" (Dutch).</li>
	</ul>
	</li>
	<li><strong>higher classifications</strong>
	<ul>
		<li>An example of such a term is “Felidae“, the biological family of cat-like carnivores.</li>
	</ul>
	</li>
</ol>

<p>It will display these matches under the header “species names” in the results page. This <em>accepted scientific name</em> will then be used for searching through multi-media and specimens.</p>

<p>It can happen that results are shown that do not contain the origanl query. These results where found by searching on the matched <em>accepted scientific name</em>.</p>

<h2>Relevance Sorting</h2>

<p>As with any common search engine, the most relevant results are listed before less relevant results. The results are listed according to:</p>

<ol>
	<li>Full match on the <strong>accepted scientific name</strong></li>
	<li>Full match on the <strong>species name</strong>
	<ul>
		<li>e.g. “Leo” in “<em>Panthera leo</em>”</li>
	</ul>
	</li>
	<li>Full match on the <strong>genus name</strong>.
	<ul>
		<li>e.g. "Panthera" in “<em>Panthera leo</em>”</li>
	</ul>
	</li>
	<li>Partial match on <strong>accepted scientific name_</strong>
	<ul>
		<li>This is the case when you search for just "Panthera"</li>
	</ul>
	</li>
	<li>Full match in any other field
	<ul>
		<li>e.g. "Smith" as the name of the collector</li>
	</ul>
	</li>
	<li>Partial match of your search in any other field</li>
</ol>

<h2>Categories</h2>

<p>The results of your results are divided in four categories:</p>

<ol>
	<li><strong>Multimedia</strong>: images, sounds and video found througout all records</li>
	<li><strong>Species-descriptions</strong> (or more genarally: <strong>taxa </strong>)
	<ul>
		<li>A <em>taxon</em> typically refers to a specific biological species, for example: *Panthera Leo" for lion. It can also be used for the name of a higher biological classification, such as "Felidae": the biological family of cat-like carnivores</li>
	</ul>
	</li>
	<li><strong>Collection specimen</strong>: are references to physical objects stored in the collection of Naturalis or other institutions. These records can contain large amounts of detailed information. Specimen results are diveded into two categories:
	<ul>
		<li><strong>Specimens</strong> with the search term in the <strong>taxon name</strong></li>
		<li><strong>Specimens</strong> with the search term in <strong>another field</strong>
		<ul>
			<li>A search on “<strong>Fox</strong>“ will yield results from collectors named Fox</li>
		</ul>
		</li>
	</ul>
	</li>
</ol>

<h2>Advanced Search</h2>

<p>An advanced search allows you to narrow down the results. You can acces the advanced search by clicking on the triangle in the search box.</p>

<p>The advanced search screen allows you to search directly through specific fields within each of the categories. The results will be limited to matches only in the specified field and only within the specified category.</p>

<p>If you enter search terms within more then one category, results will be shown for each of these categories.</p>

<p>If you enter more then one search term within one category, only records will be shown that match both terms. This behaviour can be changed by switching “<em>Combine Search Terms</em>” from “<em>And</em>” to “<em>Or</em>”.</p>

<h2>Geographic Search</h2>

<p>A <em>Geographic search</em> can be used to quickly limit the results of a search to a specific geographical area.</p>

<p>This area can be either obtained from the selection list on the right side, or from drawing a shape on the map.</p>

<p>Results for a geographic search are limited to specimen and multimedia. The results are filtered by the location where a the specimen was found: the <em>gathering site</em></p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-21 12:37:22 +0000',
  'user_uuid' => 'd4fc88d0-c5d0-4ad1-a390-c5ee98f38dd5',
);
  $nodes[] = array(
  'title' => 'Colophon',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'ds_switch' => '',
  'type' => 'naturalis_service_menu_page',
  'language' => 'und',
  'created' => 1413895260,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '794d5b17-da10-492e-839d-bbfce2ad70b4',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>The information on this website is copyrighted by Naturalis Biodiversity Center.</p>

<p>Multimedia items in search results are CC-zero, unless stated otherwise.</p>

<h2>Editing</h2>

<p>Naturalis Biodiversity Center</p>

<h2>Interaction, design and technique</h2>

<p>Naturalis Biodiversity Center, department of software development, based on work of Fabrique</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-21 12:41:00 +0000',
  'user_uuid' => 'd4fc88d0-c5d0-4ad1-a390-c5ee98f38dd5',
);
  $nodes[] = array(
  'title' => 'About',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'ds_switch' => '',
  'type' => 'naturalis_page',
  'language' => 'und',
  'created' => 1413985040,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '9c021310-9a55-495b-b798-dbbc56a1c5bb',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<h2>waar gaat deze site over?</h2>

<h2>bronsystemen</h2>

<h2>over collectie</h2>

<h3>over brahms</h3>

<h3>over CRS</h3>

<h3>over NSR</h3>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-22 13:37:20 +0000',
  'user_uuid' => 'd4fc88d0-c5d0-4ad1-a390-c5ee98f38dd5',
);
  $nodes[] = array(
  'title' => 'Contact',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'ds_switch' => '',
  'type' => 'naturalis_service_menu_page',
  'language' => 'und',
  'created' => 1413984173,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'a2f56bf1-1289-45f2-96a5-c25a057d6679',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<table border="0" style="height:146px; width:416px">
	<tbody>
		<tr>
			<td>Visiting address</td>
			<td>Darwinweg 2, 2333 CR Leiden</td>
		</tr>
		<tr>
			<td>Postadres</td>
			<td>Postbus 9517, 2300 RA Leiden</td>
		</tr>
		<tr>
			<td>Postal address</td>
			<td>+ 31-(0)71 568 7600</td>
		</tr>
		<tr>
			<td>Fax</td>
			<td>+ 31-(0)71 568 7666</td>
		</tr>
		<tr>
			<td>E-mail</td>
			<td><a href="mailto:contact@naturalis.nl" target="_blank">contact@naturalis.nl</a></td>
		</tr>
		<tr>
			<td>Office address</td>
			<td>Darwinweg 2, 2333 CR Leiden</td>
		</tr>
		<tr>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
		</tr>
		<tr>
			<td>Chamber of Commerce</td>
			<td>41169515</td>
		</tr>
		<tr>
			<td>VAT-number</td>
			<td>NL803595943B01</td>
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
  'date' => '2014-10-22 13:22:53 +0000',
  'user_uuid' => 'd4fc88d0-c5d0-4ad1-a390-c5ee98f38dd5',
);
  $nodes[] = array(
  'title' => 'For developers',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'ds_switch' => '',
  'type' => 'naturalis_page',
  'language' => 'und',
  'created' => 1413984718,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'ee159a0a-2bc8-44bd-aac9-33ce07af5273',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>De Naturalis API (Application Programming Interface) is een nieuwe, state-of-the-art service voor applicatieontwikkelaars. Via de API stelt het Naturalis collectie- en andere content en (hoge resolutie) afbeeldingen beschikbaar om te gebruiken in bijvoorbeeld apps of webtoepassingen.</p>

<h2>API</h2>

<p>De live website API (met een live koppeling op het websiteplatform) maakt alle kracht van de Award-winnende Naturalis website direct toegankelijk voor een grote groep ontwikkelaars. Met name het zoeken in de collectie, de ontdek de collectie pagina’s, de Rijksstudio gebruikersverzamelingen en de getilede beelden om diep te kunnen inzoomen op een kunstwerk, bieden vele interessante mogelijkheden. Daarnaast is er bijvoorbeeld ook agenda-informatie beschikbaar.<br />
De op Json gebaseerde service is zo eenvoudig dat je in no time iets kan bouwen dat gebruik maakt van de rijke en aantrekkelijke Naturalis content.</p>

<h2>Toegang tot de API</h2>

<p>Om toegang te krijgen tot de data en afbeeldingen dien je een API key aan te vragen. Dan kan je doen bij bij je geavanceerde instellingen in je Rijksstudio account (https://www.Naturalis.nl/rijksstudio ). Je krijg dan direct een code. Deze code heb je nodig om gebruik te maken van de api\'s.</p>

<p>Voor vragen en opmerkingen kun je mailen met: website@Naturalis.nl</p>

<p><a href="http://Naturalis.github.io/">Meer informatie over de API</a> (Op Github, Engelstalig)</p>

<h2>OAI API</h2>

<p>Sinds 2011 biedt het Naturalis ook een API aan met het zogenaamde OAI protocol (Open Achives Initiative). OAI is een standaard die in de culturele sector wordt gebruikt door net name organisaties zoals Europeana, Koninklijke Bibliotheek en het Instituut voor Beeld &amp; Geluid.<br />
<a href="https://www.Naturalis.nl/nl/api/uitleg-Naturalis-oai-api">Meer informatie over de OAI API</a></p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-22 13:31:58 +0000',
  'user_uuid' => 'd4fc88d0-c5d0-4ad1-a390-c5ee98f38dd5',
);
  return $nodes;
}
