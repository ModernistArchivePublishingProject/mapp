@api
  Feature: Welcome page
    Scenario:
      Given I am not logged in
      When I am on the homepage
      Then I should see "Welcome to The Modernist Archives Publishing Project"
      And I should see the heading "Recent Blog Posts"