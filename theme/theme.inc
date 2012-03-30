<?php

function theme_json_node_view($node) {
  return json_encode($node);
}

function theme_json_node_view_json($view = NULL, $options = NULL, $rows = NULL, $title = NULL) {
  $output = array('nodes' => $rows);
  return $output;
}

function theme_json_node_view_row_json_node($view, $options, $row) {
  _json_node_prepare_node_view($row);
  return $row;
}