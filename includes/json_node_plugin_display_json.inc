<?php

/**
 * @file
 * Contains the feed display plugin.
 */

/**
 * The plugin that handles a feed, such as RSS or atom.
 *
 * For the most part, feeds are page displays but with some subtle differences.
 *
 * @ingroup views_display_plugins
 */
class json_node_plugin_display_json extends views_plugin_display_feed {
  function get_style_type() { return 'json_feed'; }

  /**
   * Feeds do not go through the normal page theming mechanism. Instead, they
   * go through their own little theme function and then return NULL so that
   * Drupal believes that the page has already rendered itself...which it has.
   */
  function execute() {
    $output = $this->view->render();
    if (empty($output)) {
      return drupal_not_found();
    }

    json_node_encode_json($output);
  }

  function preview() {
    if (!empty($this->view->live_preview)) {
      return '<code>' . json_encode($this->view->render()) . '</code>';
    }
    return json_encode($this->view->render());
  }
}
