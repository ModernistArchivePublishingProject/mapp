<?php

class MigratePartialDateFieldHandler extends MigrateFieldHandler {
  public function __construct() {
    $this->registerTypes(array('partial_date', 'partial_date_range'));
  }

  static function arguments($txt_short = NULL, $txt_long = NULL, $data = NULL, $year = NULL, $month = NULL, $day = NULL, $hour = NULL, $minute = NULL, $second = NULL, $timezone = NULL, $year_to = NULL, $month_to = NULL, $day_to = NULL, $hour_to = NULL, $minute_to = NULL, $second_to = NULL, $timezone_to = NULL) {
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
    if (!is_null($year_to)) {
      $arguments['year_to'] = $year_to;
    }
    if (!is_null($month_to)) {
      $arguments['month_to'] = $month_to;
    }
    if (!is_null($day_to)) {
      $arguments['day_to'] = $day_to;
    }
    if (!is_null($hour_to)) {
      $arguments['hour_to'] = $hour_to;
    }
    if (!is_null($minute_to)) {
      $arguments['minute_to'] = $minute_to;
    }
    if (!is_null($second_to)) {
      $arguments['second_to'] = $second_to;
    }
    if (!is_null($timezone_to)) {
      $arguments['timezone_to'] = $timezone_to;
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
      'year_to' => t('Subfield: Year To'),
      'month_to' => t('Subfield: Month To'),
      'day_to' => t('Subfield: Day To'),
      'hour_to' => t('Subfield: Hour To'),
      'minute_to' => t('Subfield: Minute To'),
      'second_to' => t('Subfield: Second To'),
      'timezone_to' => t('Subfield: Timezone To'),
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
      $item_from = array();
      if (isset($arguments['txt_short'])) {
        $item_from['txt_short'] = $arguments['txt_short'];
      }
      if (isset($arguments['txt_long'])) {
        $item_from['txt_long'] = $arguments['txt_long'];
      }
      if (isset($arguments['data'])) {
        $item_from['data'] = $arguments['data'];
      }
      if (isset($arguments['year'])) {
        $item_from['year'] = $arguments['year'];
      }
      if (isset($arguments['month'])) {
        $item_from['month'] = $arguments['month'];
      }
      if (isset($arguments['day'])) {
        $item_from['day'] = $arguments['day'];
      }
      if (isset($arguments['hour'])) {
        $item_from['hour'] = $arguments['hour'];
      }
      if (isset($arguments['minute'])) {
        $item_from['minute'] = $arguments['minute'];
      }
      if (isset($arguments['second'])) {
        $item_from['second'] = $arguments['second'];
      }
      if (isset($arguments['timezone'])) {
        $item_from['timezone'] = $arguments['timezone'];
      }
      $item_from['timestamp'] = $value;

      $item_to = array();
      if (isset($arguments['year_to'])) {
        $item_to['year'] = $arguments['year_to'];
      }
      if (isset($arguments['month_to'])) {
        $item_to['month'] = $arguments['month_to'];
      }
      if (isset($arguments['day_to'])) {
        $item_to['day'] = $arguments['day_to'];
      }
      if (isset($arguments['hour_to'])) {
        $item_to['hour'] = $arguments['hour_to'];
      }
      if (isset($arguments['minute_to'])) {
        $item_to['minute'] = $arguments['minute_to'];
      }
      if (isset($arguments['second_to'])) {
        $item_to['second'] = $arguments['second_to'];
      }
      if (isset($arguments['timezone_to'])) {
        $item_to['timezone'] = $arguments['timezone_to'];
      }
      $item_to['timestamp'] = $value;

      $return[$language][$delta] = array('from' => $item_from, 'to' => $item_to);
    }

    return isset($return) ? $return : NULL;
  }

}

