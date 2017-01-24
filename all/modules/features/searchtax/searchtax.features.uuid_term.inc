<?php
/**
 * @file
 * searchtax.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function searchtax_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 't_order',
    'description' => 'Order',
    'format' => NULL,
    'weight' => 3,
    'uuid' => '095ca378-8c58-45c3-969a-1a7c5978da9f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/torder',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 's_youngestChronstratigraphicName',
    'description' => 'Youngest chronstratigraphic name',
    'format' => NULL,
    'weight' => 1,
    'uuid' => '0c4563de-1d29-42b9-ba60-22729600cf53',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/syoungestchronstratigraphicname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 'm_gatheringAgent',
    'description' => 'Collector',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '0c93b002-cd16-400c-a6ec-1ba08a2c929e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mgatheringagent',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => '--more--',
    'description' => '--more--',
    'format' => NULL,
    'weight' => 6,
    'uuid' => '0db9da4a-2338-418c-be05-383749713024',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/more',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 't_className',
    'description' => 'Class',
    'format' => NULL,
    'weight' => 2,
    'uuid' => '0ebf93a1-6408-4c52-9bd4-48537da8d6bc',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tclassname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 's_youngestBiostratigraphicName',
    'description' => 'Youngest biostratigraphic name',
    'format' => NULL,
    'weight' => 6,
    'uuid' => '12aae422-736a-4753-8865-2ac1d4f9e17b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/syoungestbiostratigraphicname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 'm_expertOrganisation',
    'description' => 'Expert organisation',
    'format' => NULL,
    'weight' => 6,
    'uuid' => '12f0c8ad-39a8-47f3-a80e-1c7c01de88e3',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mexpertorganisation',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_collectingStartDate',
    'description' => 'Collecting start date',
    'format' => NULL,
    'weight' => 4,
    'uuid' => '15626ca4-34f4-4636-be98-8c2aebea662a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mcollectingstartdate',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_localityText',
    'description' => '<p>Locality</p>
',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '1874f59c-0c59-487f-b2ab-7f308a89771a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mlocalitytext',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_scientificName',
    'description' => 'Scientific name',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '19515d9c-2012-4f31-adab-0249626f3e23',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/nscientificname',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/sscientificname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => '--hide--',
    'description' => '--hide--',
    'format' => NULL,
    'weight' => 15,
    'uuid' => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/hide',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 'm_taxonomicStatus',
    'description' => 'Taxonomic status',
    'format' => NULL,
    'weight' => 7,
    'uuid' => '1f7aa388-bcd7-4703-8422-04831ca75f2a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mtaxonomicstatus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_collectorsFieldNumber',
    'description' => 'Collectors field number',
    'format' => 'markdown',
    'weight' => 2,
    'uuid' => '1fb5261e-7b24-4bfe-b03f-35bb6e121354',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mcollectionfieldnumber',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/mcollectorsfieldnumber',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_sourceSystem',
    'description' => 'Source',
    'format' => 'markdown',
    'weight' => 1,
    'uuid' => '252b758f-e225-426d-96ac-b3b9f68f7637',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'm_sourceSystem',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Naturalis - Botany catalogues|Naturalis - Nederlands Soortenregister|Naturalis - Zoology and Geology catalogues',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/msourcesystem',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 'm_phylum',
    'description' => 'Phylum',
    'format' => NULL,
    'weight' => 1,
    'uuid' => '28029cae-53b0-45c5-9a5f-aafac926a6e8',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mphylum',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_sex',
    'description' => 'Sex',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '2bc7d345-6def-4b59-82c9-a3c4445c5d65',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'm_sex',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'female|hermaphrodite|male|mixed',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/msex',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 't_kingdom',
    'description' => 'Kingdom',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '32fc861e-68f3-4816-afba-4a4c6329fe4b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 't_kingdom',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Animalia|Archaea|Bacteria|Chromista|Fungi|Plantae|Protozoa|Viruses',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tkingdom',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 't_genusOrMonomial',
    'description' => 'Genus',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '33ab617b-d485-42a7-a592-c530998e9409',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tgenusormonomial',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 's_unitID',
    'description' => 'Registration number',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '34225b6c-5fba-4c11-89e7-b4ded4815039',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/sunitid',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 'Taxa',
    'description' => 'Taxa',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/taxa',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    ),
  );
  $terms[] = array(
    'name' => 'm_family',
    'description' => 'Family',
    'format' => NULL,
    'weight' => 3,
    'uuid' => '381d3a69-a9c4-46ae-b921-6c8eb5d00dc9',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mfamily',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 's_collectionType',
    'description' => 'Collection name',
    'format' => 'markdown',
    'weight' => 7,
    'uuid' => '3a89190c-0b9a-4593-9557-3154b8a8042e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 's_collectionType',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Brachiopoda|Echinodermata|Foraminifera|Hemiptera|Hydrozoa|Odonata|Orthopteroidea|Paleobotany|Pisces|Tunicata',
          'format' => NULL,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/scollectiontype',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 's_oldestChronstratigraphicName',
    'description' => 'Oldest chronstratigraphic name',
    'format' => NULL,
    'weight' => 2,
    'uuid' => '3d589c02-40ad-482e-9308-325c8ea8335d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/soldestchronstratigraphicname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_subgenus',
    'description' => 'Subgenus',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '3fbce186-b017-403e-99b7-150a7db67619',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/ssubgenus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_family',
    'description' => 'Family',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '43170a5f-503d-4304-b534-efe7e4511a7b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/nfamily',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/sfamily',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 'm_phaseOrStage',
    'description' => 'Phase or stage',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => '44d14c91-3410-470f-988d-7fb0634772c5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'm_phaseOrStage',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'adult|egg|embryo|immature|juvenile|larva|nymph|subadult',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mphaseorstage',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 't_vernacularName',
    'description' => 'Common name',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '453c7051-f8db-4fb1-b5ae-1dfe556c844d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tvernacularname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 't_subgenus',
    'description' => 'Subgenus',
    'format' => NULL,
    'weight' => 4,
    'uuid' => '461be0f8-a9b5-413f-8ee7-dc8afdcc1909',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tsubgenus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 't_expert',
    'description' => 'Expert name',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '479981df-3e8b-4ec9-86a5-6c9824ebd5b3',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/texpert',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'abf15890-2907-4350-a0b2-8a3ec2e44512',
    ),
  );
  $terms[] = array(
    'name' => 'm_biostratigraphicAttributionTypeYoung',
    'description' => 'Younest biostratigraphic name
',
    'format' => 'plain_text',
    'weight' => 14,
    'uuid' => '548c7327-9d2e-40b9-bb85-44548a4bd103',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mbiostratigraphicattributiontypeyoung',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_vernacularName',
    'description' => 'Common name
',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '5582c7fb-ded2-4077-bfcb-94e8365b72af',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/nvernacularname',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/svernacularname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 'm_unitID',
    'description' => 'Multimedia title
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '55be0171-11c8-43e8-8b31-d69a1e0e0dbc',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/munitid',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_phaseOrStage',
    'description' => 'Phase or stage',
    'format' => 'plain_text',
    'weight' => 10,
    'uuid' => '56d49d5a-2348-4289-a578-61bb5c947bd9',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 's_phaseOrStage',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'adult|egg|embryo|immature|juvenile|larva|nymph|subadult',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/sphaseorstage',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => '--more--',
    'description' => '--more--',
    'format' => NULL,
    'weight' => 14,
    'uuid' => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/more-0',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 'm_infraspecificEpithet',
    'description' => 'Infraspecific name',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '5d26d474-beeb-49a7-9405-7707474c4bf4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'm_infraspecificEpithet',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/minfraspecificepithet',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_scientificName',
    'description' => 'Scientific name',
    'format' => 'markdown',
    'weight' => 4,
    'uuid' => '60f93dbc-38d9-499f-a617-28539e8df31a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mscientificname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 'm_subgenus',
    'description' => 'subgenus',
    'format' => NULL,
    'weight' => 8,
    'uuid' => '61104e9f-e32a-4e22-bbaa-18a563f2abfc',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/msubgenus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_genusOrMonomial',
    'description' => 'Genus',
    'format' => 'markdown',
    'weight' => 5,
    'uuid' => '618d5d30-d174-43d1-9345-d57654a4b03c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mgenusormonomial',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => '--hide--',
    'description' => '--hide--',
    'format' => NULL,
    'weight' => 11,
    'uuid' => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/hide-0',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 'Multimedia',
    'description' => 'Multimedia',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'multimedia',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/multimedia',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    ),
  );
  $terms[] = array(
    'name' => 'm_order',
    'description' => 'Order',
    'format' => NULL,
    'weight' => 3,
    'uuid' => '69161391-770f-4bff-87f4-316c302d0aec',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/morder',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_biostratigraphicAttributionTypeOld',
    'description' => 'Oldest biostratigraphic name',
    'format' => NULL,
    'weight' => 13,
    'uuid' => '6c7cd901-140e-4ea6-bd8b-64ae7535d3de',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mbiostratigraphicattributiontypeold',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'Collection specimens',
    'description' => 'Collection specimens',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/collection-specimens',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    ),
  );
  $terms[] = array(
    'name' => 'm_kingdom',
    'description' => 'Kingdom',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '7908bd90-4e9e-4ff3-ae81-250317acf131',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'kingdom',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Animalia|Archaea|Bacteria|Chromista|Fungi|Plantae|Protozoa|Viruses',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mkingdom',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_vernacularName',
    'description' => 'Common name
',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '79521971-58cf-4ea3-92f2-369eae187c14',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mvernacularname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 'omnisearch',
    'description' => 'term',
    'format' => NULL,
    'weight' => 80,
    'uuid' => '7a6d1b8b-574f-4dfb-b74b-e4ea17e9d3e5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 's_sourceSystem',
    'description' => 'Source',
    'format' => 'markdown',
    'weight' => 6,
    'uuid' => '7d4df160-0941-49ae-9c74-30ba7d7372e2',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 's_sourceSystem',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Naturalis - Botany catalogues|Naturalis - Zoology and Geology catalogues',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/ssourcesystem',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/ssourcesystemname',
        'language' => 'und',
      ),
      2 => array(
        'alias' => 'search/ssourcesystem',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 'm_collectionType',
    'description' => 'Collection name',
    'format' => 'markdown',
    'weight' => 2,
    'uuid' => '7f03c683-b1d3-4cc5-aaca-4b7a24af3be9',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'm_collectionType',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Arts|Aves|Botany|Bryozoa|Cainozoic Mollusca|Cnidaria|Coleoptera|Crustacea|Diptera|Foraminifera|Hemiptera|Hymenoptera|Lepidoptera|Mammalia|Micropaleontology|Mineralogy|Mollusca|Odonata|Paleobotany|Paleontology Invertebrates|Petrology|Porifera|Vermes',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mcollectiontype',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 't_specificEpithet',
    'description' => 'Specific name
',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '93674884-b99c-442a-9bee-aec1175ac576',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 't_specificEpithet',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tspecificepithet',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 's_sex',
    'description' => 'Sex',
    'format' => 'plain_text',
    'weight' => 11,
    'uuid' => '93f35ff9-dd82-4884-ba0b-efdaf8fdfbea',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 's_sex',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'female|hermaphrodite|male|mixed',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/ssex',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 's_localityText',
    'description' => 'Locality
',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => '98cbc05f-3f0d-44e2-aa57-ef06fc984d80',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/slocalitytext',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 't_taxonomicStatus',
    'description' => 'Taxonomic status',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '9a975141-7129-41cc-8a1c-a55c118f5948',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 't_taxonomicStatus',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'basionym|homonym|synonym|valid name',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/ttaxonomicstatus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'abf15890-2907-4350-a0b2-8a3ec2e44512',
    ),
  );
  $terms[] = array(
    'name' => 'm_chronostratigraphicAttributiontTypeOld',
    'description' => 'Oldest chronostratigraphic name',
    'format' => NULL,
    'weight' => 10,
    'uuid' => '9b5a983a-a8ee-4a78-87e6-f9350471133b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mchronostratigraphicattributionttypeold',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'extended',
    'description' => 'extended',
    'format' => NULL,
    'weight' => 81,
    'uuid' => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 's_collectorsFieldNumber',
    'description' => 'Collectors field number',
    'format' => 'plain_text',
    'weight' => 13,
    'uuid' => '9e463bbe-9952-48da-a5ca-34f71f2271f6',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/scollectionfieldnumber',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/scollectorsfieldnumber',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 's_phylum',
    'description' => 'Phylum',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '9f2c4682-88b6-460d-8e9b-587f8b471737',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/nphylum',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/sphylum',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 'm_lithostratigraphicAttributionType',
    'description' => 'First lithostratigraphic name',
    'format' => NULL,
    'weight' => 11,
    'uuid' => 'a18a6420-c42a-436e-be9f-87de477a69e1',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => '--hide--',
    'description' => '--hide--',
    'format' => NULL,
    'weight' => 7,
    'uuid' => 'abf15890-2907-4350-a0b2-8a3ec2e44512',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/hide-1',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 'm_className',
    'description' => 'Class',
    'format' => NULL,
    'weight' => 2,
    'uuid' => 'b35315b4-e928-4ed0-a1bc-ec384bc5cc6e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mclassname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_expert',
    'description' => 'Expert name',
    'format' => NULL,
    'weight' => 5,
    'uuid' => 'b3d916fd-6811-498c-8905-27f38d3c755b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_typeStatus',
    'description' => 'Type status',
    'format' => 'plain_text',
    'weight' => 8,
    'uuid' => 'b8256f66-b26d-4fc7-8842-cc48feeede11',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 's_typeStatus',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => '-- all --|allotype|epitype|holotype|isoepitype|isolectotype|isoneotype|isosyntype|isotype|lectotype|neotype|paralectotype|paratype|syntype|topotype',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/stypestatus',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 's_gatheringAgent',
    'description' => 'Collector',
    'format' => 'plain_text',
    'weight' => 12,
    'uuid' => 'bb2c083f-90cd-4a64-8c78-d90f19563ea4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/sgatheringagent',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 's_genusOrMonomial',
    'description' => 'Genus',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'bc27e6d3-4ae7-4d2f-ae3d-2eeb1ddbd719',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/ngenusormonomial',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/sgenusormonomial',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 's_secondLithostratigraphicName',
    'description' => 'Second lithostratigraphic name',
    'format' => NULL,
    'weight' => 4,
    'uuid' => 'c4323256-7ac6-4929-9b01-5e0ac217ddf5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/ssecondlithostratigraphicname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_infraspecificEpithet',
    'description' => 'Infraspecific name',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'c4a8bf82-0a73-4630-bb8a-126700cd9452',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'n_infraspecificEpithet',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/ninfraspecificepithet',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/sinfraspecificepithet',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 't_infraspecificEpithet',
    'description' => 'Infraspecific name
',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => 'c7eaee57-8365-48b1-9bc5-eddbeba8210d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 't_infraspecificEpithet',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tinfraspecificepithet',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 'm_lithostratigraphicAttributionType2',
    'description' => 'Second lithostratigraphic name',
    'format' => NULL,
    'weight' => 12,
    'uuid' => 'cb52e179-647f-4292-9363-21ee9ed12587',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 't_phylum',
    'description' => 'Phylum',
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'd0a78838-d6a0-440b-a950-f7bcfb9efd84',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tphylum',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 's_kingdom',
    'description' => 'Kingdom',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd1179982-7bc2-44de-82c6-a70eeccefe9c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'n_kingdom',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Animalia|Archaea|Bacteria|Chromista|Fungi|Plantae|Protozoa|Viruses',
          'format' => NULL,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/nkingdom',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/skingdom',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 'm_chronostratigraphicAttributiontTypeYoung',
    'description' => 'Youngest chronostratigraphic name
',
    'format' => 'plain_text',
    'weight' => 9,
    'uuid' => 'd237198d-14ca-459b-a41a-4938e7e8ebd9',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_collectingStartDate',
    'description' => 'Collecting start date',
    'format' => NULL,
    'weight' => 7,
    'uuid' => 'd2997fb3-bfb6-46a2-9074-a6db473d4ba3',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/scollectingstartdate',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_oldestBiostratigraphicName',
    'description' => 'Oldest biostratigraphic name',
    'format' => NULL,
    'weight' => 5,
    'uuid' => 'd3f6f460-cd4d-446a-b5a2-9fbab31cec7c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/soldestbiostratigraphicname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_firstLithostratigraphicName',
    'description' => 'First lithostratigraphic name',
    'format' => NULL,
    'weight' => 3,
    'uuid' => 'dce82d80-9fba-41ca-bcce-e23628f22566',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/sfirstlithostratigraphicname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 'm_specificEpithet',
    'description' => 'Specific name',
    'format' => 'plain_text',
    'weight' => 6,
    'uuid' => 'deb807f4-558d-49ec-973b-057a4b570e47',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'm_specificEpithet',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 't_expertOrganisation',
    'description' => 'Expert organisation',
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'df111ae5-11b6-4ab0-bff2-f9d81cf3b045',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/texpertorganisation',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => 'abf15890-2907-4350-a0b2-8a3ec2e44512',
    ),
  );
  $terms[] = array(
    'name' => 's_specificEpithet',
    'description' => 'Specific name
',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => 'e3956f71-9c9e-41dd-a5f3-f656df13ad90',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 's_specificEpithet',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/nspecificepithet',
        'language' => 'und',
      ),
      1 => array(
        'alias' => 'search/sspecificepithet',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  $terms[] = array(
    'name' => 's_className',
    'description' => 'Class',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'e7ec7114-3f31-4988-a955-0205dd43a697',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 0,
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 't_sourceSystem',
    'description' => 'Source',
    'format' => 'markdown',
    'weight' => 1,
    'uuid' => 'eff23bd4-46a4-4f1b-93cd-b8e506d20c11',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => 'Naturalis - Nederlands Soortenregister|Species 2000 - Catalogue Of Life',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tsourcesystem',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 'm_typeStatus',
    'description' => 'Type status',
    'format' => 'plain_text',
    'weight' => 7,
    'uuid' => 'f25d70fd-e86b-4719-86a1-d8916b17f840',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(
      'und' => array(
        0 => array(
          'value' => 'm_typeStatus',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(
      'und' => array(
        0 => array(
          'value' => '-- all --|allotype|epitype|holotype|isoepitype|isolectotype|isoneotype|isosyntype|isotype|lectotype|neotype|paralectotype|paratype|syntype|topotype',
          'format' => NULL,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => '--more--',
    'description' => '--more--',
    'format' => NULL,
    'weight' => 10,
    'uuid' => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 't_family',
    'description' => 'Family',
    'format' => NULL,
    'weight' => 2,
    'uuid' => 'fceb4c7d-3ac5-4e70-ac7e-f810b8b3643c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tfamily',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 's_order',
    'description' => 'Order',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => 'fe616d3d-a1f9-4ef3-af77-6ace87e54b5f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'search',
    'field_ndadatatype' => array(),
    'field_ndageorelevance' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_ndasystem' => array(),
    'field_ndavalues' => array(),
    'path' => array(
      'pathauto' => 0,
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  return $terms;
}
