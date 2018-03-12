@api

  Feature: Menus
    In order to navigate the website
    As an anonymous user
    I should be able to access all the menu items


    Scenario Outline: Navigate site by main menu
      Given I am not logged in
      When I am on the homepage
      Then I should see the link <link> in the "Main Menu" region
      Examples:
      | link      |
      | About     |
      | Browse    |
      | Search    |
      | Teaching  |
      | Team      |
      | Contact   |

    Scenario Outline: Navigate footer menu
      Given I am not logged in
      When I am on the homepage
      Then I should see the link <link> in the "Footer Menu" region
      Examples:
      | link                          |
      | Bibliography                  |
      | "Funders & Partners"          |
      | "Publications & Presentations"|
      | "Terms & Conditions"          |
      | Login                         |