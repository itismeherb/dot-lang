# Contributing to Dot

Thank you for your interest in contributing to Dot! Even though the project is small right now, contributions of any kind, including bug fixes, documentation improvements, or new features are welcome.

---

## Workflow

1. Fork the repository.
2. Create a short-lived feature branch from `dev`:
```bash
   git checkout dev
   git checkout -b feat/your-feature-name
```
3. Keep commits focused and small — ideally one conceptual change per commit.
4. Ensure the compiler builds and passes any tests before committing.
5. Push your branch and open a pull request against the `dev` branch.

---

## Branches

- `master` – stable branch, always builds.
- `dev` – integration branch for active development.
- `feat/*` – feature branches.
- `bug/*` – bug fix branches.
- `refactor/*` – refactoring branches.

---

## Commit Messages

Use the following format for commit messages:

```
<subsystem>: <imperative summary>
```

**Subsystem examples:**
- `lexer`
- `parser`
- `ast`
- `typecheck`
- `codegen`
- `util`
- `tests`

**Examples:**
```
parser: add recursive descent skeleton
ast: introduce BinaryExpr node
codegen: emit correct mov instructions
```

**Guidelines:**
- One concept per commit.
- Prefer clarity over cleverness.
- Do not print errors in library code; return error codes instead.

---

## Documentation & Links

- [Documentation](docs/START.md)
- [License](LICENSE)
