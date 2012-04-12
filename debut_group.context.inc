<?php
/**
 * @file
 * debut_group.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function debut_group_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group-content-type';
  $context->description = 'When viewing a group, show contextual information.';
  $context->tag = 'Content types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'group' => 'group',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-new' => array(
          'module' => 'user',
          'delta' => 'new',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-og_members-block_1' => array(
          'module' => 'views',
          'delta' => 'og_members-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'group',
    'menu' => 'node/add/group',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content types');
  t('When viewing a group, show contextual information.');
  $export['group-content-type'] = $context;

  return $export;
}
