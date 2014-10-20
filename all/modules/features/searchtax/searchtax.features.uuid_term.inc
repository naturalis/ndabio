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
    'weight' => 70,
    'uuid' => '095ca378-8c58-45c3-969a-1a7c5978da9f',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 's_youngestChronstratigraphicName',
    'description' => 'Youngest chronstratigraphic name',
    'format' => NULL,
    'weight' => 45,
    'uuid' => '0c4563de-1d29-42b9-ba60-22729600cf53',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 'm_gatheringAgent',
    'description' => 'Collector',
    'format' => NULL,
    'weight' => 21,
    'uuid' => '0c93b002-cd16-400c-a6ec-1ba08a2c929e',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => '--more--',
    'description' => '--more--',
    'format' => NULL,
    'weight' => 66,
    'uuid' => '0db9da4a-2338-418c-be05-383749713024',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 't_className',
    'description' => 'Class',
    'format' => NULL,
    'weight' => 69,
    'uuid' => '0ebf93a1-6408-4c52-9bd4-48537da8d6bc',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 's_youngestBiostratigraphicName',
    'description' => 'Youngest biostratigraphic name',
    'format' => NULL,
    'weight' => 50,
    'uuid' => '12aae422-736a-4753-8865-2ac1d4f9e17b',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 'm_expertOrganisation',
    'description' => 'Expert organisation',
    'format' => NULL,
    'weight' => 24,
    'uuid' => '12f0c8ad-39a8-47f3-a80e-1c7c01de88e3',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_collectingStartDate',
    'description' => 'Collecting start date',
    'format' => NULL,
    'weight' => 22,
    'uuid' => '15626ca4-34f4-4636-be98-8c2aebea662a',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_localityText',
    'description' => 'Locality text',
    'format' => NULL,
    'weight' => 10,
    'uuid' => '1874f59c-0c59-487f-b2ab-7f308a89771a',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => '--hide--',
    'description' => '--hide--',
    'format' => NULL,
    'weight' => 43,
    'uuid' => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 'm_taxonomicStatus',
    'description' => 'Taxonomic status',
    'format' => NULL,
    'weight' => 25,
    'uuid' => '1f7aa388-bcd7-4703-8422-04831ca75f2a',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_collectionFieldNumber',
    'description' => 'Collection field number',
    'format' => NULL,
    'weight' => 19,
    'uuid' => '1fb5261e-7b24-4bfe-b03f-35bb6e121354',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_phylum',
    'description' => 'Phylum',
    'format' => NULL,
    'weight' => 13,
    'uuid' => '28029cae-53b0-45c5-9a5f-aafac926a6e8',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_sex',
    'description' => 'Sex',
    'format' => NULL,
    'weight' => 18,
    'uuid' => '2bc7d345-6def-4b59-82c9-a3c4445c5d65',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 't_kingdom',
    'description' => 'Kingdom',
    'format' => NULL,
    'weight' => 67,
    'uuid' => '32fc861e-68f3-4816-afba-4a4c6329fe4b',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 't_genusOrMonomial',
    'description' => 'Genus or monomial',
    'format' => NULL,
    'weight' => 63,
    'uuid' => '33ab617b-d485-42a7-a592-c530998e9409',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 's_unitID',
    'description' => 'Registration number',
    'format' => NULL,
    'weight' => 34,
    'uuid' => '34225b6c-5fba-4c11-89e7-b4ded4815039',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 'Taxa',
    'description' => 'Taxa',
    'format' => NULL,
    'weight' => 60,
    'uuid' => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    ),
  );
  $terms[] = array(
    'name' => 'm_family',
    'description' => 'Family',
    'format' => NULL,
    'weight' => 6,
    'uuid' => '381d3a69-a9c4-46ae-b921-6c8eb5d00dc9',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 's_oldestChronstratigraphicName',
    'description' => 'Oldest chronstratigraphic name',
    'format' => NULL,
    'weight' => 46,
    'uuid' => '3d589c02-40ad-482e-9308-325c8ea8335d',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_subgenus',
    'description' => 'Subgenus',
    'format' => NULL,
    'weight' => 44,
    'uuid' => '3fbce186-b017-403e-99b7-150a7db67619',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_family',
    'description' => 'Family',
    'format' => NULL,
    'weight' => 36,
    'uuid' => '43170a5f-503d-4304-b534-efe7e4511a7b',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 'm_phaseOrStage',
    'description' => 'Phase or stage',
    'format' => NULL,
    'weight' => 17,
    'uuid' => '44d14c91-3410-470f-988d-7fb0634772c5',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 't_vernacularName',
    'description' => 'Vernacular name',
    'format' => NULL,
    'weight' => 61,
    'uuid' => '453c7051-f8db-4fb1-b5ae-1dfe556c844d',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 't_subgenus',
    'description' => 'Subgenus',
    'format' => NULL,
    'weight' => 71,
    'uuid' => '461be0f8-a9b5-413f-8ee7-dc8afdcc1909',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 't_expert',
    'description' => 'Expert name',
    'format' => NULL,
    'weight' => 72,
    'uuid' => '479981df-3e8b-4ec9-86a5-6c9824ebd5b3',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 'm_biostratigraphicAttributionTypeYoung',
    'description' => 'Younest biostratigraphic name',
    'format' => NULL,
    'weight' => 32,
    'uuid' => '548c7327-9d2e-40b9-bb85-44548a4bd103',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_vernacularName',
    'description' => 'Vernacular name',
    'format' => NULL,
    'weight' => 35,
    'uuid' => '5582c7fb-ded2-4077-bfcb-94e8365b72af',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 'm_unitID',
    'description' => 'Registration number',
    'format' => NULL,
    'weight' => 4,
    'uuid' => '55be0171-11c8-43e8-8b31-d69a1e0e0dbc',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 's_phaseOrStage',
    'description' => 'Phase or stage',
    'format' => NULL,
    'weight' => 41,
    'uuid' => '56d49d5a-2348-4289-a578-61bb5c947bd9',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => '--more--',
    'description' => '--more--',
    'format' => NULL,
    'weight' => 51,
    'uuid' => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 'm_subspeciesEpithet',
    'description' => 'Subspecies epithet',
    'format' => NULL,
    'weight' => 16,
    'uuid' => '5d26d474-beeb-49a7-9405-7707474c4bf4',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_subgenus',
    'description' => 'subgenus',
    'format' => NULL,
    'weight' => 26,
    'uuid' => '61104e9f-e32a-4e22-bbaa-18a563f2abfc',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_genusOrMonomial',
    'description' => 'Genus or monomial',
    'format' => NULL,
    'weight' => 7,
    'uuid' => '618d5d30-d174-43d1-9345-d57654a4b03c',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => '--hide--',
    'description' => '--hide--',
    'format' => NULL,
    'weight' => 20,
    'uuid' => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 'Multimedia',
    'description' => 'Multimedia',
    'format' => NULL,
    'weight' => 3,
    'uuid' => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    ),
  );
  $terms[] = array(
    'name' => 'm_order',
    'description' => 'Order',
    'format' => NULL,
    'weight' => 15,
    'uuid' => '69161391-770f-4bff-87f4-316c302d0aec',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_biostratigraphicAttributionTypeOld',
    'description' => 'Oldest biostratigraphic name',
    'format' => NULL,
    'weight' => 31,
    'uuid' => '6c7cd901-140e-4ea6-bd8b-64ae7535d3de',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'm_kingdom',
    'description' => 'Kingdom',
    'format' => NULL,
    'weight' => 12,
    'uuid' => '7908bd90-4e9e-4ff3-ae81-250317acf131',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_vernacularName',
    'description' => 'Vernacular name',
    'format' => NULL,
    'weight' => 5,
    'uuid' => '79521971-58cf-4ea3-92f2-369eae187c14',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 'omnisearch',
    'description' => 'term',
    'format' => NULL,
    'weight' => 1,
    'uuid' => '7a6d1b8b-574f-4dfb-b74b-e4ea17e9d3e5',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
  );
  $terms[] = array(
    'name' => 't_speciesEpithet',
    'description' => 'Species epithet',
    'format' => NULL,
    'weight' => 64,
    'uuid' => '93674884-b99c-442a-9bee-aec1175ac576',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 's_sex',
    'description' => 'Sex',
    'format' => NULL,
    'weight' => 42,
    'uuid' => '93f35ff9-dd82-4884-ba0b-efdaf8fdfbea',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 's_localityText',
    'description' => 'Locality text',
    'format' => NULL,
    'weight' => 40,
    'uuid' => '98cbc05f-3f0d-44e2-aa57-ef06fc984d80',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 't_taxonomicStatus',
    'description' => 'Taxonomic status',
    'format' => NULL,
    'weight' => 74,
    'uuid' => '9a975141-7129-41cc-8a1c-a55c118f5948',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 'm_chronostratigraphicAttributiontTypeOld',
    'description' => 'Oldest chronostratigraphic name',
    'format' => NULL,
    'weight' => 28,
    'uuid' => '9b5a983a-a8ee-4a78-87e6-f9350471133b',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 'extended',
    'description' => 'extended',
    'format' => NULL,
    'weight' => 2,
    'uuid' => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
  );
  $terms[] = array(
    'name' => 's_collectionFieldNumber',
    'description' => 'Collection field number',
    'format' => NULL,
    'weight' => 59,
    'uuid' => '9e463bbe-9952-48da-a5ca-34f71f2271f6',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 's_phylum',
    'description' => 'Phylum',
    'format' => NULL,
    'weight' => 53,
    'uuid' => '9f2c4682-88b6-460d-8e9b-587f8b471737',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 'm_lithostratigraphicAttributionType',
    'description' => 'First lithostratigraphic name',
    'format' => NULL,
    'weight' => 29,
    'uuid' => 'a18a6420-c42a-436e-be9f-87de477a69e1',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => '--hide--',
    'description' => '--hide--',
    'format' => NULL,
    'weight' => 75,
    'uuid' => 'abf15890-2907-4350-a0b2-8a3ec2e44512',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 'm_className',
    'description' => 'Class',
    'format' => NULL,
    'weight' => 14,
    'uuid' => 'b35315b4-e928-4ed0-a1bc-ec384bc5cc6e',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    ),
  );
  $terms[] = array(
    'name' => 'm_expert',
    'description' => 'Expert name',
    'format' => NULL,
    'weight' => 23,
    'uuid' => 'b3d916fd-6811-498c-8905-27f38d3c755b',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_typeStatus',
    'description' => 'Type status',
    'format' => NULL,
    'weight' => 39,
    'uuid' => 'b8256f66-b26d-4fc7-8842-cc48feeede11',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 's_gatheringAgent',
    'description' => 'Collector',
    'format' => NULL,
    'weight' => 57,
    'uuid' => 'bb2c083f-90cd-4a64-8c78-d90f19563ea4',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 's_genusOrMonomial',
    'description' => 'Genus or monomial',
    'format' => NULL,
    'weight' => 37,
    'uuid' => 'bc27e6d3-4ae7-4d2f-ae3d-2eeb1ddbd719',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 's_secondLithostratigraphicName',
    'description' => 'Second lithostratigraphic name',
    'format' => NULL,
    'weight' => 48,
    'uuid' => 'c4323256-7ac6-4929-9b01-5e0ac217ddf5',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_subspeciesEpithet',
    'description' => 'Subspecies epithet',
    'format' => NULL,
    'weight' => 56,
    'uuid' => 'c4a8bf82-0a73-4630-bb8a-126700cd9452',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 't_subspeciesEpithet',
    'description' => 'Subspecies epithet',
    'format' => NULL,
    'weight' => 65,
    'uuid' => 'c7eaee57-8365-48b1-9bc5-eddbeba8210d',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 'm_lithostratigraphicAttributionType2',
    'description' => 'Second lithostratigraphic name',
    'format' => NULL,
    'weight' => 30,
    'uuid' => 'cb52e179-647f-4292-9363-21ee9ed12587',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 't_phylum',
    'description' => 'Phylum',
    'format' => NULL,
    'weight' => 68,
    'uuid' => 'd0a78838-d6a0-440b-a950-f7bcfb9efd84',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 's_kingdom',
    'description' => 'Kingdom',
    'format' => NULL,
    'weight' => 52,
    'uuid' => 'd1179982-7bc2-44de-82c6-a70eeccefe9c',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 'm_chronostratigraphicAttributiontTypeYoung',
    'description' => 'Youngest chronostratigraphic name',
    'format' => NULL,
    'weight' => 27,
    'uuid' => 'd237198d-14ca-459b-a41a-4938e7e8ebd9',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '6372fb61-264c-490a-9c8f-8e8b9c28af04',
    ),
  );
  $terms[] = array(
    'name' => 's_collectingStartDate',
    'description' => 'Collecting start date',
    'format' => NULL,
    'weight' => 58,
    'uuid' => 'd2997fb3-bfb6-46a2-9074-a6db473d4ba3',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 's_oldestBiostratigraphicName',
    'description' => 'Oldest biostratigraphic name',
    'format' => NULL,
    'weight' => 49,
    'uuid' => 'd3f6f460-cd4d-446a-b5a2-9fbab31cec7c',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 's_firstLithostratigraphicName',
    'description' => 'First lithostratigraphic name',
    'format' => NULL,
    'weight' => 47,
    'uuid' => 'dce82d80-9fba-41ca-bcce-e23628f22566',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '1a3baf4e-b243-44fd-9e87-e6dced3b650f',
    ),
  );
  $terms[] = array(
    'name' => 'm_speciesEpithet',
    'description' => 'Species epithet',
    'format' => NULL,
    'weight' => 8,
    'uuid' => 'deb807f4-558d-49ec-973b-057a4b570e47',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 't_expertOrganisation',
    'description' => 'Expert organisation',
    'format' => NULL,
    'weight' => 73,
    'uuid' => 'df111ae5-11b6-4ab0-bff2-f9d81cf3b045',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '0db9da4a-2338-418c-be05-383749713024',
    ),
  );
  $terms[] = array(
    'name' => 's_speciesEpithet',
    'description' => 'Species epithet',
    'format' => NULL,
    'weight' => 38,
    'uuid' => 'e3956f71-9c9e-41dd-a5f3-f656df13ad90',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    ),
  );
  $terms[] = array(
    'name' => 'Collection specimens',
    'description' => 'Collection specimens',
    'format' => NULL,
    'weight' => 33,
    'uuid' => 'e408d24d-bdac-4fe5-b68d-edd9e224f8ca',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '9d7db5bf-a8ec-4b5c-b2a7-923387ea1009',
    ),
  );
  $terms[] = array(
    'name' => 's_className',
    'description' => 'Class',
    'format' => NULL,
    'weight' => 54,
    'uuid' => 'e7ec7114-3f31-4988-a955-0205dd43a697',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  $terms[] = array(
    'name' => 'm_typeStatus',
    'description' => 'Type status',
    'format' => NULL,
    'weight' => 9,
    'uuid' => 'f25d70fd-e86b-4719-86a1-d8916b17f840',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => '--more--',
    'description' => '--more--',
    'format' => NULL,
    'weight' => 11,
    'uuid' => 'f35538ec-5291-40ca-bc5d-abde8fe36984',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '658088c0-2fbb-4a7c-93f9-d4e5a6dbf43f',
    ),
  );
  $terms[] = array(
    'name' => 't_family',
    'description' => 'Family',
    'format' => NULL,
    'weight' => 62,
    'uuid' => 'fceb4c7d-3ac5-4e70-ac7e-f810b8b3643c',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '34470bff-c926-4fd4-b0c4-e5c1c1b64258',
    ),
  );
  $terms[] = array(
    'name' => 's_order',
    'description' => 'Order',
    'format' => NULL,
    'weight' => 55,
    'uuid' => 'fe616d3d-a1f9-4ef3-af77-6ace87e54b5f',
    'vocabulary_machine_name' => 'search',
    'field_system' => array(),
    'parent' => array(
      0 => '5bc93b06-21dd-4761-b4a2-e4c3b3ae4296',
    ),
  );
  return $terms;
}
