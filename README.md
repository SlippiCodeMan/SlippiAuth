# Slippi Auth

An (unoffical) authenticator for slippi accounts.

## How does it work

Slippi-auth is a service that provides authentication using a slippi account. It works by faking a netplay player which the person wanting to authentify has to connect to in direct mode.

## Installation

1. Clone the repo:

```sh 
git clone https://github.com/ananas-dev/slippi-auth
cd slippi-auth
```

2. Create accounts that will be used by the authenticator, you'll need to grab their uids and play keys found in their `user.json` then put them in a file called `clients.json` in the slippi-auth directory:

```json
[
  {
    "uid": "redacted",
    "playKey": "redacted",
    "connectCode": "XYZ#111"
  },
  {
    "uid": "redacted",
    "playKey": "redacted",
    "connectCode": "XYZ#222"
  }
]
```

3. Run the service:

```sh
go run https://github.com/ananas-dev/slippi-auth
```

## Usage

Slippi-auth starts a websocket server on [0.0.0.0:9002](0.0.0.0:9002) you can then communicate with it using this workflow:

### Queue an user

First you have to send the connected code of the user you want to authenticate and the timeout in ms.

```json
{
    "type": "queue",
    "code": "XXX#123",
    "timeout": 60000
}
```

### Server response

The response of the server will contain the queued connect code and depends on the outcome:

✅ User has been authenticated

```json
{
    "type": "success",
    "code": "XXX#123"
}
```

❌ Authentication timed out:

```json
{
    "type": "timeout",
    "code": "XXX#123"
}
```

❌ There was an error:

```json
{
    "type": "err",
    "code": "XXX#123"
}
```

❌ There are no available authentication clients:

```json
{
    "type": "full",
    "code": "XXX#123"
}
```
