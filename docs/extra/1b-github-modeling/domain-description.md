# GitHub Domain Description

## Overview

GitHub is a web-based service for hosting Git repositories and supporting collaborative software development.

The main domain concepts are repositories, users, branches, commits, pull requests, reviews, issues, and CI workflows.

## Main Actors

### Developer

A developer writes code, creates branches, commits changes, pushes them to GitHub, opens pull requests, and responds to review comments.

### Reviewer

A reviewer checks proposed changes in a pull request and provides feedback.

### Maintainer

A maintainer manages the repository and can merge pull requests.

### CI System

The CI system automatically runs checks after code changes are pushed or after a pull request is opened.

## Main Workflows

### Repository Workflow

A user creates or clones a repository, makes changes locally, commits them, and pushes them to GitHub.

### Pull Request Workflow

A developer creates a branch, pushes changes, opens a pull request, waits for CI checks and review, updates the pull request if needed, and finally gets it merged.

### Issue Workflow

A user creates an issue, the team discusses it, a developer works on it, and the issue is closed when the problem is solved.

## Design Notes

The conceptual model focuses on the most important domain entities and relationships.

The model intentionally does not describe all GitHub features because the real service is very large. The selected diagrams focus on repository collaboration, code review, issue tracking, and CI integration.
