@api
  Feature:
    In order to learn about the MAPP team
    As an anonymous user
    I should be able to read about each person
  Scenario Outline: Team members
    Given I am not logged in
    When I am on "/content/team"
    Then I should see <text> in the "Content"
    Examples:
    | text                        |
    | "Claire Battershill"        |
    | "Elizabeth Willson Gordon"  |
    | "Helen Southworth"          |
    | "Alice Staveley"            |
    | "Michael Widner"            |
    | "Nicola Wilson"             |

  Scenario Outline: Headings
    Given I am not logged in
    When I am on "/content/team"
    Then I should see the heading <heading>
    Examples:
    | heading                             |
    | "Research Fellows"                  |
    | "Project Manager"                   |
    | "Research Assistants"               |
    | "The King's University, Edmonton"   |
    | "Reading University"                |
    | "Simon Fraser University"           |
    | "Stanford University"               |
    | "University of Oregon"              |