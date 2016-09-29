<?php

class MigratePartialDateFieldHandler extends MigrateFieldHandler {
  public function __construct() {
    $this->registerTypes(array('partial_date'));
  }

  static function arguments($txt_short = NULL, $txt_long = NULL, $data = NULL, $year = NULL, $month = NULL, $day = NULL, $hour = NULL, $minute = NULL, $second = NULL, $timezone = NULL) {
    $arguments = array();
    if (!is_null($txt_short)) {
      $arguments['txt_short'] = $txt_short;
    }
    if (!is_null($txt_long)) {
      $arguments['txt_long'] = $txt_long;
    }
    if (!is_null($data)) {
      $arguments['data'] = $data;
    }
    if (!is_null($year)) {
      $arguments['year'] = $year;
    }
    if (!is_null($month)) {
      $arguments['month'] = $month;
    }
    if (!is_null($day)) {
      $arguments['day'] = $day;
    }
    if (!is_null($hour)) {
      $arguments['hour'] = $hour;
    }
    if (!is_null($minute)) {
      $arguments['minute'] = $minute;
    }
    if (!is_null($second)) {
      $arguments['second'] = $second;
    }
    if (!is_null($timezone)) {
      $arguments['timezone'] = $timezone;
    }
    return $arguments;
  }

  public function fields($type, $instance, $migration = NULL) {
    return array(
      'txt_short' => t('Subfield: Short text'),
      'txt_long' => t('Subfield: Long text'),
      'data' => t('Subfield: Data'),
      'year' => t('Subfield: Year'),
      'month' => t('Subfield: Month'),
      'day' => t('Subfield: Day'),
      'hour' => t('Subfield: Hour'),
      'minute' => t('Subfield: Minute'),
      'second' => t('Subfield: Second'),
      'timezone' => t('Subfield: Timezone'),
    );
  }

  public function prepare($entity, array $field_info, array $instance, array $values) {
    if (isset($values['arguments'])) {
      $arguments = $values['arguments'];
      unset($values['arguments']);
    }
    else {
      $arguments = array();
    }

    $language = $this->getFieldLanguage($entity, $field_info, $arguments);
    $values = array_filter($values);

    foreach ($values as $delta => $value) {
      $item = array();
      if (isset($arguments['txt_short'])) {
        $item['txt_short'] = $arguments['txt_short'];
      }
      if (isset($arguments['txt_long'])) {
        $item['txt_long'] = $arguments['txt_long'];
      }
      if (isset($arguments['data'])) {
        $item['data'] = $arguments['data'];
      }
      if (isset($arguments['year'])) {
        $item['year'] = $arguments['year'];
      }
      if (isset($arguments['month'])) {
        $item['month'] = $arguments['month'];
      }
      if (isset($arguments['day'])) {
        $item['day'] = $arguments['day'];
      }
      if (isset($arguments['hour'])) {
        $item['hour'] = $arguments['hour'];
      }
      if (isset($arguments['minute'])) {
        $item['minute'] = $arguments['minute'];
      }
      if (isset($arguments['second'])) {
        $item['second'] = $arguments['second'];
      }
      if (isset($arguments['timezone'])) {
        $item['timezone'] = $arguments['timezone'];
      }

      $item['timestamp'] = $value;
      $return[$language][$delta] = array('from' => $item);
    }

    return isset($return) ? $return : NULL;
  }

}
