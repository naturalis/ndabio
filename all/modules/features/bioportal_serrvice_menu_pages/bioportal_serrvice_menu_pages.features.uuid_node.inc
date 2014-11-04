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
  'body' => array(),
  'date' => '2014-10-21 14:58:21 +0200',
  'user_uuid' => '5a2bebc3-0d64-4581-a74c-7598dfea05c6',
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

<p>If you need more fine-grained control over the search results, you can use  <strong><em>advanced search</em></strong>, by clicking on the arrow in the search field.</p>

<h2>Name Resolution</h2>

<p>BioPortal will try to match your search term with one or more <em>accepted scientific  name(s)</em></p>

<p>The matching of your search term to <em>accepted scientific names</em> is done by searching through various fields of our databases:</p>

<ol>
<li><strong>qualified scientific species name</strong>.

<ul>
<li>An example of such a name is: “<em>Panthera leo</em>”</li>
</ul>
</li>
<li>a list of <strong>common names</strong>

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
<li>Full match on the <em>accepted scientific name</em></li>
<li>Full match on the <em>species</em> name

<ul>
<li>e.g. “Leo” in “<em>Panthera leo</em>”</li>
</ul>
</li>
<li>Full match on the <em>genus</em> name.

<ul>
<li>e.g. "Panthera" in “<em>Panthera leo</em>”</li>
</ul>
</li>
<li>Partial match on <em>accepted scientific name</em>

<ul>
<li>This is the case when you search for "Panthera", this shoul</li>
</ul>
</li>
<li>Full match of your search in any other field

<ul>
<li>e.g. "Smith" as the name of the collector</li>
</ul>
</li>
<li>Partial match of your search in any other field</li>
</ol>


<h2>Advanced Search</h2>

<h2>Geographic Search</h2>

<h2>Term handling</h2>',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'date' => '2014-10-21 14:37:22 +0200',
  'user_uuid' => '5a2bebc3-0d64-4581-a74c-7598dfea05c6',
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
  'body' => array(),
  'date' => '2014-10-21 14:41:00 +0200',
  'user_uuid' => '5a2bebc3-0d64-4581-a74c-7598dfea05c6',
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
  'date' => '2014-10-22 15:37:20 +0200',
  'user_uuid' => '5a2bebc3-0d64-4581-a74c-7598dfea05c6',
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
  'date' => '2014-10-22 15:22:53 +0200',
  'user_uuid' => '5a2bebc3-0d64-4581-a74c-7598dfea05c6',
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
  'date' => '2014-10-22 15:31:58 +0200',
  'user_uuid' => '5a2bebc3-0d64-4581-a74c-7598dfea05c6',
);
  return $nodes;
}
