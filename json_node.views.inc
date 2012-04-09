<?php


function json_node_views_plugins() {
  $path = drupal_get_path('module', 'json_node');
  $plugins = array(
    'module' => 'json_node', // This just tells our themes are elsewhere.
    'display' => array(
      'json_node_display' => array(
        'title' => t('JSON Feed'),
        'handler' => 'json_node_plugin_display_json',
        'path' => $path . '/includes',
        'parent' => 'feed', // so it knows to load the page plugin .inc file
        'help' => t('Display the view as a JSON feed.'),
        'admin' => t('JSON Feed'),

        'uses hook menu' => TRUE,
        'base' => array('node'), // only works with 'node' as base.
      ),
    ),
    'style' => array(
      'json_node_style' => array(
        'title' => t('JSON Feed'),
        'handler' => 'json_node_plugin_style_json',
        'path' => $path . '/includes',
        'help' => t('Generates an JSON feed from a view.'),
        'theme' => 'json_node_view_json',
        'theme path' => $path . '/theme',
        'theme file' => 'theme.inc',

        'uses row plugin' => TRUE,
        'uses options' => FALSE,
        'type' => 'json_feed',
        'base' => array('node'), // only works with 'node' as base.
      ),
    ),
    'row' => array(
      'json_node_row' => array(
        'title' => t('JSON Node'),
        'handler' => 'json_node_plugin_row_json',
        'path' => $path . '/includes',
        'help' => t('Display the node with special JSON display.'),

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
