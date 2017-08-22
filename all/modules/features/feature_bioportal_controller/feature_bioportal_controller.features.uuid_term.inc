<?php
/**
 * @file
 * feature_bioportal_controller.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function feature_bioportal_controller_uuid_features_default_terms() {
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 6,
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
    'field_ndalabel' => array(),
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
    'name' => 'license',
    'description' => 'license',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '0dad6c98-97dd-41ea-82e9-8782a04950f8',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/license',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'Family',
    'description' => 'family',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '0ff80917-a4d6-4602-9b20-0d2c40524d35',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/family-0',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'weight' => 9,
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
    'field_ndalabel' => array(),
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
    'weight' => 7,
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
    'field_ndalabel' => array(),
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
    'name' => 'sourceInstitutionID',
    'description' => 'Institution',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '15e50579-4702-4509-b77e-ee4cc2cfdd54',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sourceinstitutionid',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'localityText',
    'description' => 'locality',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '16dc449e-36ca-4a8c-87af-100b656e8f6c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/localitytext',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_localityText',
    'description' => '<p>Locality</p>
',
    'format' => 'plain_text',
    'weight' => 4,
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
    'field_ndalabel' => array(),
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
    'description' => 'Scientific name ',
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
    'field_ndalabel' => array(
      'und' => array(
        0 => array(
          'value' => 'Scientific name',
          'format' => NULL,
        ),
      ),
    ),
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
    'weight' => 16,
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
    'field_ndalabel' => array(),
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
    'name' => 'Specific name',
    'description' => 'specific name',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '1a4c0770-5950-47b4-9783-716230c7aad4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/specific-name',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_taxonomicStatus',
    'description' => 'Taxonomic status',
    'format' => NULL,
    'weight' => 10,
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
    'field_ndalabel' => array(),
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
    'weight' => 5,
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
    'field_ndalabel' => array(),
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
    'name' => 'specificEpithet',
    'description' => 'specific name',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '21fa65b6-b064-4835-8ff7-b05f57f07d98',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/specificepithet',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'family',
    'description' => 'family',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '229527a5-d529-465f-9a36-c80b6b1905b5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/family',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_sourceSystem',
    'description' => 'Source',
    'format' => 'markdown',
    'weight' => 5,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'Basis of record',
    'description' => 'Basis of record',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '28545072-6195-4494-95b0-0721c01c295d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/basis-record',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'phylum',
    'description' => 'Phylum',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2a802db0-c206-466a-969a-21f1f004bcc5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/phylum',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_sex',
    'description' => 'Sex',
    'format' => 'plain_text',
    'weight' => 1,
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
    'field_ndalabel' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/msex',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'sourceID',
    'description' => 'source id
',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2bc88353-675b-4c2c-950a-02d85d84bb1d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sourceid',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Collecting start date',
    'description' => 'Collecting start date',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '2e063a66-a28e-41a7-adf3-596091417b1e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collecting-start-date',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 2,
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
    'field_ndalabel' => array(),
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
    'weight' => 2,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'dateTimeBegin',
    'description' => 'collecting start date',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3a9bd272-91fc-42c5-b513-f2599ba06161',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'className',
    'description' => 'class',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3ab82811-072a-4bc7-9886-71e212f2f1c6',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/classname',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'institution',
    'description' => 'source institution',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3ad44115-0f24-4f2c-988d-e751532a50aa',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/institution',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'name' => 'kindOfUnit',
    'description' => 'part',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3e689df7-1ed6-4ca1-a437-ed95bc675ea9',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/kindofunit',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 2,
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
    'field_ndalabel' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mphaseorstage',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 't_vernacularName',
    'description' => 'Common name',
    'format' => 'plain_text',
    'weight' => 1,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'genusOrMonomial',
    'description' => 'genus',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '481afad4-f569-4baa-b38a-33362ed65707',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/genusormonomial',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Institution',
    'description' => 'Institution',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '4d06915b-732b-4086-b2b3-dc596cf2d3a5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/institution-0',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'otherSpecimens',
    'description' => 'other specimens',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '50e9ad90-9022-493e-8408-e6110b3e8b9c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/otherspecimens-0',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Preparation method',
    'description' => 'Preparation method',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '52f35973-2e89-476f-a9cd-a18774ae31dc',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/preparation-method',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'infraspecificEpithet',
    'description' => 'infraspecific name',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '534aff72-8e31-42ab-bf1c-39eccca2de5a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/infraspecificepithet',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_biostratigraphicAttributionTypeYoung',
    'description' => 'Younest biostratigraphic name
',
    'format' => 'plain_text',
    'weight' => 17,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(
      'und' => array(
        0 => array(
          'value' => 'Common name',
          'format' => NULL,
        ),
      ),
    ),
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
    'weight' => 3,
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
    'field_ndalabel' => array(),
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
    'name' => 't_scientificName',
    'description' => 'Scientific name',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '56a509e3-7621-495c-a21e-f2b828bdf04c',
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
    'field_ndalabel' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tscientificname',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 's_phaseOrStage',
    'description' => 'Phase or stage',
    'format' => 'plain_text',
    'weight' => 11,
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
    'field_ndalabel' => array(),
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
    'weight' => 15,
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
    'field_ndalabel' => array(),
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
    'name' => 'unitID',
    'description' => 'registration number',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5c38317e-7a8c-4028-9597-45d915605982',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/unitid',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'name' => 'sourceSystemId',
    'description' => 'system id',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5eac6ebe-7770-41bf-aca1-aa2c46a1bda0',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sourcesystemid',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_scientificName',
    'description' => 'Scientific name',
    'format' => 'markdown',
    'weight' => 0,
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
    'field_ndalabel' => array(),
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
    'weight' => 11,
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
    'field_ndalabel' => array(),
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
    'weight' => 3,
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
    'field_ndalabel' => array(),
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
    'weight' => 9,
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
    'field_ndalabel' => array(),
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
    'name' => 'SpecimenTypeStatus',
    'description' => 'Typestatus',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '639fa982-9878-4584-a0f5-708a14195de3',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/specimentypestatus',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Multimedia',
    'description' => 'Multimedia',
    'format' => 'plain_text',
    'weight' => 3,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 16,
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
    'field_ndalabel' => array(),
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
    'name' => 'genus',
    'description' => 'genus',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '703992aa-f931-4e71-a442-a7c80280d6ca',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/genus',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'title',
    'description' => 'title',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '70b39707-2532-4e1c-bb37-7a1e46f940c1',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/title',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'sexes',
    'description' => 'sex',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '7153ab73-6bfe-4c7f-b94f-702d9c05e960',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sexes',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Class',
    'description' => 'class',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '753765da-6c00-4b97-ab94-510e519b662d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/class',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'creator',
    'description' => 'creator',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '759b1bdc-e46d-4cb7-931e-3ebfa02dc5e0',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/creator',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'siteCoordinates',
    'description' => 'site coordinates',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '761a6045-7834-44be-bc20-150efc8d5275',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sitecoordinates',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Collection specimens',
    'description' => 'Collection specimens',
    'format' => 'plain_text',
    'weight' => 1,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 1,
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
    'field_ndalabel' => array(),
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
    'weight' => 84,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 6,
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
    'field_ndalabel' => array(),
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
    'name' => 'phaseOrStage',
    'description' => 'phase or stage',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '841b706f-ac29-41cb-bb33-d6125a649252',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/phaseorstage',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'description',
    'description' => 'description',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '84682775-a10c-4d99-81e1-3ef2d805b00a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/description',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'preparationType',
    'description' => 'preparation method',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '85a22acf-4972-4aec-b850-91dba233c294',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/preparationtype',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OtherSpecimens',
    'description' => 'other specimens',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '876ea642-1bc7-4265-bfa4-19677c0b4b8a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/otherspecimens',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'gatheringAgents',
    'description' => 'collector',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '87afe0ad-9b1a-45d7-8c1e-ab78d0b955da',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(
      'und' => array(
        0 => array(
          'value' => 'collector',
          'format' => NULL,
        ),
      ),
    ),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/gatheringagents',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'source',
    'description' => 'source',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '89d0de23-7446-4a26-8728-485896e4e9cb',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/source',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'collectionType',
    'description' => 'collection name',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8c6d3106-adaa-4e2c-9770-59f12eb8cfa4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collectiontype',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'kingdom',
    'description' => 'kingdom',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8d42583a-708a-4668-95d2-ccef1876a348',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/kingdom',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'caption',
    'description' => 'caption',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '90b6aab9-abaa-400c-a313-d32775441fb2',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/caption',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'typeStatus',
    'description' => 'type status',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '92f23ba1-2047-4c3d-a05c-a8bc3da60d4b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/typestatus',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'weight' => 12,
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
    'field_ndalabel' => array(),
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
    'weight' => 10,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 13,
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
    'field_ndalabel' => array(),
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
    'weight' => 85,
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
    'field_ndalabel' => array(),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 's_collectorsFieldNumber',
    'description' => 'Collectors field number',
    'format' => 'plain_text',
    'weight' => 14,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'weight' => 14,
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
    'field_ndalabel' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'copyrightText',
    'description' => 'copyright',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a197ac18-e48b-4563-85e6-03d1ab80378b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/copyrighttext',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'species',
    'description' => 'species',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a2ebad0c-11c3-4ecb-810f-8fd6f228182b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/species',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Collectors field number',
    'description' => 'Collectors field number',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'a3ef2682-4358-45ec-9e67-42995420449d',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collectors-field-number',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Part',
    'description' => 'Part',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'a643f544-36b4-47e0-b6f9-665967060a14',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/part',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'name' => 'sex',
    'description' => 'sex',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'afe4d99f-3fcb-49c7-8015-343c1db66460',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sex',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'weight' => 8,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'GatheringEvent',
    'description' => 'GatheringEvent',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bb018b96-ff8e-49d0-8101-e7cc1714b33b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/gatheringevent',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 's_gatheringAgent',
    'description' => 'Collector',
    'format' => 'plain_text',
    'weight' => 13,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'recordBasis',
    'description' => 'basis of record',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bd57062f-e424-4649-9a38-d3c82fc0c2bb',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/recordbasis',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_license',
    'description' => 'License',
    'format' => 'markdown',
    'weight' => 7,
    'uuid' => 'c272d971-f1bc-4728-8b79-ad8b62d232c8',
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
    'field_ndalabel' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/mlicense',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
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
    'field_ndalabel' => array(),
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
          'value' => 's_infraspecificEpithet',
          'format' => NULL,
        ),
      ),
    ),
    'field_ndavalues' => array(),
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/tinfraspecificepithet',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 'm_lithostratigraphicAttributionType2',
    'description' => 'Second lithostratigraphic name',
    'format' => NULL,
    'weight' => 15,
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
    'field_ndalabel' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'numberOfSpecimen',
    'description' => 'number of specimens',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cd856700-a807-4794-b17e-cd9d2620e087',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/numberofspecimen',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Other specimens',
    'description' => 'Other specimens',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'cfeae946-83f6-4d6f-842d-d98fdf029e62',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/other-specimens',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
          'value' => 's_kingdom',
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
    'field_ndalabel' => array(),
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
    'weight' => 12,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'collectorsFieldNumber',
    'description' => 'collectors field number',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dd24107d-176d-40fe-9aef-56261c4d716c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collectorsfieldnumber-0',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_specificEpithet',
    'description' => 'Specific name',
    'format' => 'plain_text',
    'weight' => 4,
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
    'field_ndalabel' => array(),
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
    'field_ndalabel' => array(),
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
    'name' => 'order',
    'description' => 'order',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dfb76785-1107-4c0d-acd7-4e2fa4df4e6a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/order',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Number of specimens',
    'description' => 'Number of specimens',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'e2169f6f-b664-492d-a59b-a4c2088f08c1',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/number-specimens',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Collection name',
    'description' => 'Collection name',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'e2a060ef-4ff1-428d-ab1f-55a718800f46',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collection-name',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'name' => 'Species n',
    'description' => 'Species with specimens',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
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
    'field_ndalabel' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/species-n',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
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
    'field_ndalabel' => array(),
    'path' => array(
      'pathauto' => 0,
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 'Phase or stage',
    'description' => 'Phase or stage',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'e7f78485-64dc-4488-9183-209c19b2283e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/phase-or-stage',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'CollectionName',
    'description' => 'Collection name',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => 'e9529ceb-48de-4837-bf83-27a7300d53b4',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collectionname',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 't_sourceSystem',
    'description' => 'Source',
    'format' => 'markdown',
    'weight' => 5,
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
    'field_ndalabel' => array(),
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
    'name' => 'multiMediaPublic',
    'description' => 'multimedia',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f09681c8-d9a4-43ef-b192-c64ef08c6703',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/multimediapublic',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'assemblageID',
    'description' => 'collection number',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f1acf885-614e-4d0b-a0be-2691f495868f',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/assemblageid',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'm_typeStatus',
    'description' => 'Type status',
    'format' => 'plain_text',
    'weight' => 0,
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
    'field_ndalabel' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => '--more--',
    'description' => '--more--',
    'format' => NULL,
    'weight' => 8,
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
    'field_ndalabel' => array(),
    'url_alias' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 'fullName',
    'description' => 'collector',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f7f3df5a-1e15-4255-abe8-c32179cae273',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/fullname',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
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
    'name' => 'owner',
    'description' => 'owner',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'fe546ae8-148a-49cb-b69c-7200ac0d326a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'field_label' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/owner',
        'language' => 'und',
      ),
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
    'field_ndalabel' => array(),
    'path' => array(
      'pathauto' => 0,
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 's_kindOfUnit',
    'description' => 'Kind of unit',
    'format' => 'markdown',
    'weight' => 9,
    'uuid' => 'fe755df0-08d1-4244-8a16-18dce0311b57',
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
    'field_ndalabel' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(
      0 => array(
        'alias' => 'search/skindofunit',
        'language' => 'und',
      ),
    ),
    'parent' => array(
      0 => '770ee2b2-de8b-4aa3-962d-d1f07188b41e',
    ),
  );
  return $terms;
}
