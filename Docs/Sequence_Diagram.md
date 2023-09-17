- The key interactions are:

- Main initializes WiFi and Cloud connections
- On each switch change:
    - Switch interacts with LED to set state
    - Switch updates cloud
    - Switch returns new state to Main
- Main loops in idle state
```mermaid
sequenceDiagram
participant Main
participant WiFi
participant Switch

Main->>WiFi: Connect
WiFi-->>Main: Connected

loop Idle
    Main->>+Switch: On/Off?
    alt On
        Switch->>Switch: Set LED On
        Switch->>Switch: Update Cloud
    else Off
        Switch->>Switch: Set LED Off
        Switch->>Switch: Update Cloud
    end

    Switch-->>-Main: Switch Changed
end
```
