<?php
/**
 * @file
 * Contains the RSS style plugin.
 */

/**
 * Default style plugin to render an RSS feed.
 *
 * @ingroup views_style_plugins
 */
class json_node_plugin_style_json extends views_plugin_style {

  function render() {
    if (empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }
    $rows = array();

    foreach ($this->view->result as $row_index => $row) {
      $this->view->row_index = $row_index;
      $rows[] = $this->row_plugin->render($row);
    }

    $output = theme($this->theme_functions(), $this->view, $this->options, $rows);
    unset($this->view->row_index);
    return $output;
  }
}
