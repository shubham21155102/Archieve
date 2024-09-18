# React Component Life Cycle

The component’s lifecycle consists of three phases:

- **Mounting lifecycle methods**

  - that is inserting elements into the DOM.

  - Following Methods are called during mounting
    - Constructor()
    - static getDerivedStateFromProps()
    - render()
    - componentDidMount()

- **Updating**
  - which involves methods for updating components in the DOM.
  - Following Methods are called during updating
    - static getDerivedStateFromProps()
    - shouldComponentUpdate()
    - render()
    - getSnapshotBeforeUpdate()
    - componentDidUpdate()
- **Unmounting**
  - that is removing a component from the DOM.
  - Following Methods are called during unmounting
    - componentWillUnmount()
