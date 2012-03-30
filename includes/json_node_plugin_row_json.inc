<?php
/**
 * @file
 * Contains the node view row style plugin.
 */

/**
 * Plugin which performs a node_view on the resulting object.
 *
 * Most of the code on this object is in the theme function.
 */
class json_node_plugin_row_json extends views_plugin_row {
  // Basic properties that let the row style follow relationships.
  var $base_table = 'node';
  var $base_field = 'nid';

  function render($row) {
    $nid = $row->{$this->field_alias};
    if (!is_numeric($nid)) {
      return;
    }

    // Load the specified node:
    $node = node_load($nid);
    if (empty($node)) {
      return;
    }

    return theme($this->theme_functions(), $this->view, $this->options, $node);
  }
}
