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
    'description' => 'Locality',
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
    'name' => 'specificEpithet',
    'description' => 'Specific Epithet',
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
    'description' => 'Family',
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
    'description' => 'Source
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
    'name' => 'dateTimeBegin',
    'description' => 'Collection start date',
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
    'description' => 'Class',
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
    'name' => 'kindOfUnit',
    'description' => 'Kind of unit',
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
    'name' => 'infraspecificEpithet',
    'description' => 'Infraspecific Epithet',
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
    'name' => 'sourceSystemId',
    'description' => 'System',
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
    'name' => 'genus',
    'description' => 'Genus',
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
    'name' => 'creator',
    'description' => 'Creator',
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
    'description' => 'Site coordinates',
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
    'name' => 'description',
    'description' => 'Description',
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
    'description' => 'Preparation',
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
    'name' => 'gatheringAgents',
    'description' => 'Collector',
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
    'description' => 'Source',
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
    'description' => 'Collection',
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
    'description' => 'Kingdom',
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
    'description' => 'Caption',
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
    'name' => 'copyrightText',
    'description' => 'Copyright',
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
    'description' => 'Species',
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
    'name' => 'recordBasis',
    'description' => 'Basis of record',
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
    'description' => 'Number of species',
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
    'name' => 'order',
    'description' => 'Order',
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
    'name' => 'multiMediaPublic',
    'description' => 'Multimedia',
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
    'description' => 'Assemblage',
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
    'name' => 'owner',
    'description' => 'Owner',
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