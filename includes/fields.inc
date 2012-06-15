<?php

function _json_node_field_process($node, $field, $info) {
  switch($info['type']) {
    case 'content_taxonomy':
      // add taxonomy inforation to content taxonomy fields.
      if (!empty($node->$field)) {
        foreach($node->$field as $k => $v) {
          $tid = $node->{$field}[$k]['value'];
          $node->{$field}[$k]['term'] = $node->taxonomy[$tid];
        }
      }
      break;
  }
}
