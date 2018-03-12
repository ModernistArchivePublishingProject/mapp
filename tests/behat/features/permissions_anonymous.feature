@api
Feature: Anonymous permissions
  Scenario Outline:
    Given I am not logged in
    When I go to <page>
    Then I should see "Access denied" in the "Page Title"
    Examples:
      | page                            |
      | "/node/add/blog"                |
      | "/node/add/business"            |
      | "/node/add/correspondence"      |
      | "/node/add/edition"             |
      | "/node/add/library"             |
      | "/node/add/person"              |
      | "/node/add/primary_object"      |
      | "/node/add/related_materials"   |
      | "/node/add/teaching_materials"  |
      | "/node/add/work"                |
    And the response status code should be 403






