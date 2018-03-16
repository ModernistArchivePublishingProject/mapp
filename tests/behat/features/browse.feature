@api

Feature: Browse
  In order to discover content
  As an anonymous user
  I should be able to browse content

  Scenario: Landing page for browsing
    Given I am not logged in
    When I am on "/browse"
    Then I should see the link "Works" in the "Content" region
    And I should see the link "People" in the "Content" region
    And I should see the link "Presses" in the "Content" region


  Scenario: Works gallery
    Given I am not logged in
    When I am on "/works"
    Then I should see "Works Gallery" in the "Page Title"
    And I should see "A random selection from our archive" in the "Content"
    And I should see the link "View All Works" in the "Content"
    # Check for some content formatted how we want
    And I should see a "span.work-author" element
    And I should see a "span.work-title" element
    And I should see a "a.work-cover" element