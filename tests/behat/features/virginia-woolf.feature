@api

  Feature: Read Virginia Woolf's page
    Scenario Outline: Page headers
      Given I am not logged in
      When I am on "/person/virginia-woolf"
      Then I should see the heading <heading>

      Examples:
      | heading                   |
      | Gender                    |
      | Occupation                |
      | "Birth Date"              |
      | "Birth Place"             |
      | "Death Date"              |
      | "Death Place"             |
      | Relationships             |
      | "Business Relationships"  |
      | "Authority Record"        |
      | "Works Authored"          |

    Scenario:
      Given I am not logged in
      When I am on "/person/virginia-woolf"
      Then I should see "Portrait of Virginia Woolf" in the "Right Group"
      And I should see a "figure.field-name-field-image" element

    Scenario Outline: Works Authored
      Given I am not logged in
      When I am on "/person/virginia-woolf"
      Then I should see <title> in the "Works Authored" region
      Examples:
      | title                       |
      | "A Room of One's Own"       |
      | "Kew Gardens"               |
      | "Jacob's Room"              |
      | "A Letter to a Young Poet"  |