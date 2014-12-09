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
  
  'path' => array(
    'alias' => 'disclaimer'
  ),
  
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Every effort has been taken to ensure the accuracy of the information on biportal.naturalis.nl.</p><p>However, Naturalis Biodiversity Center excludes all and any liability for damage resulting from the use, in whatever manner, of information supplied on this site.</p><h2>Intellectual Property Rights</h2><p>Every effort has been taken to protect the interests of third parties when using data, texts and pictures. If, however, you believe that this site contains material that is subject to intellectual property rights without agreements having been made with the rightful owner, please contact the web editors.</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'date' => '2014-10-21 12:58:21 +0000',
  'user_uuid' => '6674d160-2235-4419-95f1-37b7fc943703',
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

  'path' => array(
    'alias' => 'disclaimer'
  ),

  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<div class="body field"><p>Op deze site kan je zoeken op multimedia, specimen (collectie exemplaren), taxa (soortbeschrijvingen) en op dieren, planten, paddenstoelen, fossielen en stenen.</p><p>De informatie komt uit de catalogi van Naturalis Biodiversity Center in Leiden, uit het <a href="http://www.nederlandsesoorten.nl/" style="text-decoration:none;"><u>Nederlands Soorten Register</u></a> en uit de <a href="http://www.catalogueoflife.org/" style="text-decoration:none;"><u>Catalogue of Life</u></a></p><p>De BioPortal biedt vier mogelijkheden om deze gegevens te doorzoeken: <em>simple search</em>, <em>advanced search</em>, <em>geographic search </em>en <em>explore highlights</em></p><h2>Zoeken</h2><h3><strong>Simple Search</strong></h3><p>Bioportaal werkt net zoals bekende zoekmachines: het gebruikt jouw zoekterm om onze bronnen te doorzoeken. Het doorzoekt daarbij alle velden die in de <em>advanced search </em>vermeld zijn (zoals de <em>populaire naam</em>, de <em>wetenschappelijke naam</em> of de vindplaats) en zelfs velden die ook met de <em>advanced search </em>niet doorzoekbaar zijn.</p><p><em>Voorbeeld</em>: je kan zowel op [ bruine rat ] als op [ rattus norvegicus ] zoeken.</p><p>Wanneer je meer dan één zoekterm invult, tonen we alle resultaten waarin één van beide termen voorkomt, maar we tonen resultaten met beide termen boven aan de lijst.</p><h3><strong>Advanced Search</strong></h3><p>Door op het driehoekje in het invulveld te klikken, verlaat je de <em>simple search</em> en begin je aan een <em>advanced search</em>. Hiermee beperk je de resultaten tot de categorie waarin je zoekt (multimedia, specimen of taxa) en tot de specifieke velden waarin je zoekt.</p><p>Wanneer je voor meer categorieën zoektermen opgeeft, worden voor elke categorie resultaten getoond.</p><p>Als je binnen een categorie meerdere zoekvelden invult, worden aanvankelijk slechts resultaten getoond die beide termen bevatten. Je <em>beperkt</em> hier het aantal resultaten mee.</p><p>Wanneer je &ldquo;OR&rdquo; kiest voor &ldquo;combine search terms&rdquo; krijg je daarbij resultaten te zien die één van beide termen bevatten en breidt je de resultaten uit.</p><h3><strong>Geographic Search</strong></h3><p>Geografisch zoeken kan gebruikt worden om de zoekresultaten snel te beperken tot een bepaald gebied. Dit gebied kan gekozen worden uit een lijst gebieden aan de rechterkant van de kaart of op de kaart getekend worden.</p><p>De resultaten zijn altijd beperkt tot exemplaren en multimedia. Alleen resultaten waarvan de geografische coördinaten van de vindplaats opgenomen zijn in de bronsystemen, worden hier getoond.</p><h3><strong>Explore Highlights</strong></h3><p>Een eenvoudige en snelle manier van zoeken is &ldquo;Explore Highlights&rdquo;. Hiermee zie je alle exemplaren die behoren tot een van de Bijzondere Collecties van Naturalis. Je krijgt direct de resultaten te zien.</p><h2>Zoekresultaten</h2><p>BioPortal probeert je snel de resultaten te geven die je zoekt en gebruikt daarvoor <em>name resolution</em> en <em>ranking</em>.</p><h3><strong>Name resolution</strong></h3><p>Het BioPortaal zal trachten jouw zoekterm te <em>matchen</em> met een wetenschappelijke naam. Dit wordt gedaan door verschillende velden te doorzoeken van het <a href="http://www.nederlandsesoorten.nl/" style="text-decoration:none;"><u>Nederlands Soorten Register</u></a> en de [Catalogue of Life]:</p><ol><li><p>Wetenschappelijke naam</p><ul><li><p>Bijvoorbeeld: <em>&ldquo;Rattus norvegicus&rdquo;</em></p></li></ul></li><li><p>Een lijst met populaire namen in verschillende talen</p><ul><li><p>Een voorbeeld is &ldquo;Bruine Rat&rdquo; (Nederlands) of &ldquo;Brown Rat &rdquo; (Engels)</p></li></ul></li><li><p>Hogere ordeningen</p><ul><li><p>Bijvoorbeeld &ldquo;Rodentia&rdquo; voor de biologische orde van de knaagdieren</p></li></ul></li></ol><p>&nbsp;</p><p>Deze wetenschappelijke naam wordt vervolgens gebruikt voor het doorzoeken van multimedia en exemplaren. Hierdoor kan het zijn dat je jouw oorspronkelijke zoekopdracht niet letterlijk terugziet in sommige resultaten.</p><h3><strong>Ranking</strong></h3><p>De zoekresultaten worden geordend aan de hand van</p><ol><li><p>Volledige <em>match</em> op de wetenschappelijke naam</p></li><li><p>Volledige <em>match</em> op de soortnaam</p></li><li><p>Volledige <em>match</em> op de naam van het geslacht</p></li><li><p>Gedeeltelijke <em>match</em> op de wetenschappelijke nam</p></li><li><p>Volledige <em>match</em> op enig ander veld</p></li><li><p>Gedeeltelijke <em>match</em> op enig ander veld</p></li></ol><h3><strong>Categorieën</strong></h3><p>De zoekresulaten zijn verdeeld over vier categorieën:</p><ol><li><p>Multimedia: afbeeldingen, geluid of bewegend beeld uit alle gegevens</p></li><li><p>Taxa (soortbeschrijvingen)</p></li><li><p>Specimen (collectie exemplaren). Dit zijn verwijzingen naar en beschrijvingen van objecten die zijn opgeslagen in de collectie van Naturalis (en soms ook daarbuiten). Deze beschrijvingen kunnen veel verschillende velden bevatten. Deze categorie is opgedeeld in:</p><ul><li><p>Exemplaren met de zoekterm in de soortnaam</p></li><li><p>Exemplaren met de zoekterm in een ander veld.</p><ul><li>&ldquo;Rat&rdquo; levert ook resultaten op voor &ldquo;Rat Island&rdquo; in Plymout, U.K.</li></ul></li></ul></li></ol></div>',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'date' => '2014-10-21 12:37:22 +0000',
  'user_uuid' => '6674d160-2235-4419-95f1-37b7fc943703',
);
  $nodes[] = array(
  'title' => 'API',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'ds_switch' => '',
  'type' => 'naturalis_page',
  'language' => 'en',
  'created' => 1417081488,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '400c73b8-5ad3-44eb-a513-c019e8ef8fce',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>De Naturalis API (Application Programming Interface) is een nieuwe, state-of-the-art service voor applicatieontwikkelaars. Via de API stelt het Naturalis collectie- en andere content en (hoge resolutie) afbeeldingen beschikbaar om te gebruiken in bijvoorbeeld apps of webtoepassingen.</p><h2>API</h2><p>De live website API (met een live koppeling op het websiteplatform) maakt alle kracht van de Award-winnende Naturalis website direct toegankelijk voor een grote groep ontwikkelaars. Met name het zoeken in de collectie, de ontdek de collectie pagina&rsquo;s, de Rijksstudio gebruikersverzamelingen en de getilede beelden om diep te kunnen inzoomen op een kunstwerk, bieden vele interessante mogelijkheden. Daarnaast is er bijvoorbeeld ook agenda-informatie beschikbaar.<br />De op Json gebaseerde service is zo eenvoudig dat je in no time iets kan bouwen dat gebruik maakt van de rijke en aantrekkelijke Naturalis content.</p><h2>Toegang tot de API</h2><p>Om toegang te krijgen tot de data en afbeeldingen dien je een API key aan te vragen. Dan kan je doen bij bij je geavanceerde instellingen in je Rijksstudio account (https://www.Naturalis.nl/rijksstudio ). Je krijg dan direct een code. Deze code heb je nodig om gebruik te maken van de api&#39;s.</p><p>Voor vragen en opmerkingen kun je mailen met: website@Naturalis.nl</p><p><a href="http://Naturalis.github.io/">Meer informatie over de API</a> (Op Github, Engelstalig)</p><h2>OAI API</h2><p>Sinds 2011 biedt het Naturalis ook een API aan met het zogenaamde OAI protocol (Open Achives Initiative). OAI is een standaard die in de culturele sector wordt gebruikt door net name organisaties zoals Europeana, Koninklijke Bibliotheek en het Instituut voor Beeld &amp; Geluid.<br /><a href="https://www.Naturalis.nl/nl/api/uitleg-Naturalis-oai-api">Meer informatie over de OAI API</a></p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'date' => '2014-11-27 09:44:48 +0000',
  'user_uuid' => '6674d160-2235-4419-95f1-37b7fc943703',
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
        'value' => '<p>The information on this website is copyrighted by Naturalis Biodiversity Center.</p><p>Multimedia items in search results are CC-zero, unless stated otherwise.</p><h2>Editing</h2><p>Naturalis Biodiversity Center</p><h2>Interaction, design and technique</h2><p>Naturalis Biodiversity Center, department of software development, based on work of Fabrique</p>',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'date' => '2014-10-21 12:41:00 +0000',
  'user_uuid' => '6674d160-2235-4419-95f1-37b7fc943703',
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
        'value' => '<h2>waar gaat deze site over?</h2><h2>bronsystemen</h2><h2>over collectie</h2><h3>over brahms</h3><h3>over CRS</h3><h3>over NSR</h3>',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'date' => '2014-10-22 13:37:20 +0000',
  'user_uuid' => '6674d160-2235-4419-95f1-37b7fc943703',
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
        'value' => '<h2>Vragen en suggesties over BioPortal</h2><table border="0" style="width:100%"><tbody><tr><td style="width:50%">e-mail</td><td>bioportal@naturalis.nl</td></tr></tbody></table><h2>Naturalis Biodiversity Center</h2><table border="0" style="width:100%"><tbody><tr><td style="width:50%">Visiting address</td><td>Darwinweg 2, 2333 CR Leiden</td></tr><tr><td>Postadres</td><td>Postbus 9517, 2300 RA Leiden</td></tr><tr><td>Postal address</td><td>+ 31-(0)71 568 7600</td></tr><tr><td>Fax</td><td>+ 31-(0)71 568 7666</td></tr><tr><td>E-mail</td><td><a href="mailto:contact@naturalis.nl" target="_blank">contact@naturalis.nl</a></td></tr><tr><td>Office address</td><td>Darwinweg 2, 2333 CR Leiden</td></tr><tr><td>&nbsp;</td><td>&nbsp;</td></tr><tr><td>Chamber of Commerce</td><td>41169515</td></tr><tr><td>VAT-number</td><td>NL803595943B01</td></tr></tbody></table>',
        'summary' => '',
        'format' => 'full_html',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'date' => '2014-10-22 13:22:53 +0000',
  'user_uuid' => '6674d160-2235-4419-95f1-37b7fc943703',
);
  return $nodes;
}
