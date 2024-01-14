import random
import gym
import numpy as np
from IPython.display import clear_output
import matplotlib.pyplot as plt
import time


def update_q_table(Q, s, a, r, sprime, alpha, gamma):   
    """
    This function should update the Q function for a given pair of action-state
    following the q-learning algorithm, it takes as input the Q function, the pair action-state,
    the reward, the next state sprime, alpha the learning rate and gamma the discount factor.
    Return the same input Q but updated for the pair s and a.
    """
    current_value = Q[s][a]
    max_future_value = np.max(Q[sprime])
    new_value = current_value + alpha * (r + gamma * max_future_value - current_value)
    Q[s][a] = new_value
    return Q
    
    
    


def epsilon_greedy(Q, s, epsilone):
    """
    This function implements the epsilon greedy algorithm.
    Takes as unput the Q function for all states, a state s, and epsilon.
    It should return the action to take following the epsilon greedy algorithm.
    """
    if (random.randint(0,100) < epsilone*100):
        return env.action_space.sample()  # Explore
    else:
        return np.argmax(Q[s])  # Exploit


if __name__ == "__main__":
    env = gym.make("Taxi-v3", render_mode="rgb_array")

    env.reset()
    env.render()

    Q = np.zeros([env.observation_space.n, env.action_space.n])

    alpha = 0.7 # choose your own

    gamma = 0.4 # choose your own

    epsilon = 0.01 # choose your own

    n_epochs = 400 # choose your own
    max_itr_per_epoch = 10000 # choose your own
    rewards = []

    for e in range(n_epochs):
        r = 0

        S, _ = env.reset()

        for _ in range(max_itr_per_epoch):
            A = epsilon_greedy(Q=Q, s=S, epsilone=epsilon)

            Sprime, R, done, _, info = env.step(A)

            Q = update_q_table(
                Q=Q, s=S, a=A, r=R, sprime=Sprime, alpha=alpha, gamma=gamma
            )

            # Update state and put a stoping criteria
            r += R
            S = Sprime

            if done:
                break

        print("episode #", e, " : r = ", r)

        rewards.append(r)

    print("Average reward = ", np.mean(rewards))
    print("Average of last 10 rewards = ", np.mean(rewards[-10:]))

    # plot the rewards in function of epochs

    print("Training finished.\n")

    
    """
    
    Evaluate the q-learning algorihtm
    
    """
    
    plt.plot(rewards)
    plt.xlabel("Epochs")
    plt.ylabel("Reward")
    plt.title("Reward vs Epochs")
    plt.show()

    env.close()
