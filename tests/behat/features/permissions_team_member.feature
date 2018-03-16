@api
  Feature: Team Member permissions
    Scenario Outline:
      Given I am logged in as a user with the "Team Member" role
      Then I should be able to edit a <type> content
      Examples:
      | type                  |
      | "Blog entry"          |
      | "Business"            |
      | "Correspondence"      |
      #| "Edition"             | # Throws error not related to permissions
      | "Library"             |
      | "Person"              |
      | "Primary Object"      |
      | "Related Materials"   |
      | "Teaching Materials"  |
      | "Work"                |

  Scenario Outline:
    Given I am logged in as a user with the "Team Member" role
    When I go to <page>
    Then I should not see "Access denied" in the "Page Title"
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


