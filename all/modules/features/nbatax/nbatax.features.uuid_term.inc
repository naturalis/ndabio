<?php
/**
 * @file
 * nbatax.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nbatax_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'license',
    'description' => 'license',
    'format' => 'markdown',
    'weight' => 0,
    'uuid' => '0dad6c98-97dd-41ea-82e9-8782a04950f8',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/license',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/family-0',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/localitytext',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/specific-name',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/family',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/phylum',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collecting-start-date',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/institution',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/kindofunit',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/infraspecificepithet',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/unitid',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sourcesystemid',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/specimentypestatus',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sitecoordinates',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/gatheringagents',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'source',
    'description' => 'source system',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '89d0de23-7446-4a26-8728-485896e4e9cb',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/caption',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'typeStatus',
    'description' => 'typestatus',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '92f23ba1-2047-4c3d-a05c-a8bc3da60d4b',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/typestatus',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/part',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/sex',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/recordbasis',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'numberOfSpecimen',
    'description' => 'Count',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'cd856700-a807-4794-b17e-cd9d2620e087',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/other-specimens',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collectorsfieldnumber-0',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'order',
    'description' => 'orde',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dfb76785-1107-4c0d-acd7-4e2fa4df4e6a',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'nba2text',
    'metatags' => array(),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collection-name',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/collectionname',
        'language' => 'und',
      ),
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
    'metatags' => array(),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/assemblageid',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/fullname',
        'language' => 'und',
      ),
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
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'nba2text/owner',
        'language' => 'und',
      ),
    ),
  );
  return $terms;
}
