<?php


function json_node_views_plugins() {
  $path = drupal_get_path('module', 'json_node');
  $plugins = array(
    'module' => 'json_node', // This just tells our themes are elsewhere.
    'display' => array(
      'json_feed' => array(
        'title' => t('JSON Feed'),
        'admin' => t('JSON Feed'),
        'help' => t('Display the view as a JSON feed.'),
        'handler' => 'json_node_plugin_display_json_feed',
        'parent' => 'page', // so it knows to load the page plugin .inc file
        'uses hook menu' => TRUE,
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'accept attachments' => FALSE,
        'path' => $path . '/includes',
        'base' => array('node'), // only works with 'node' as base.
      ),
    ),
    'style' => array(
      'json' => array(
        'title' => t('JSON Feed'),
        'help' => t('Generates an JSON feed from a view.'),
        'handler' => 'json_node_plugin_style_json',
        'theme' => 'json_node_view_json',
        'theme path' => $path . '/theme',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses options' => FALSE,
        'type' => 'json_feed',
        'path' => $path . '/includes',
        'base' => array('node'), // only works with 'node' as base.
      ),
    ),
    'row' => array(
      'json_node' => array(
        'title' => t('JSON Node'),
        'help' => t('Display the node with special JSON display.'),
        'handler' => 'json_node_plugin_row_json',
        'path' => $path . '/includes',
        'base' => array('node'), // only works with 'node' as base.
        'uses options' => FALSE,
        'uses fields' => FALSE,
        'type' => 'json_feed',
        'theme' => 'json_node_view_row_json_node',
        'theme path' => $path . '/theme',
        'theme file' => 'theme.inc',
      ),
    ),
  );
  return $plugins;
}
